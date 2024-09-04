import random

def get_hosts(setting):
    hosts = [
        {
            "id": i,
            "status": 0,         # 0: standby, 1: send, 2: resend
            "action_to_do": 0,   # 0: standby, 1: send, 2: resend, 3: stop sending
            "packet_num": 0,   
            "remain_length": 0,  # remain time to sending
            "wait_time": 0,      # time wait to send
            "collision": False,
            "success_num": 0,
            "collision_num": 0,
            "history": "",       # record history of host's actions
        }
        for i in range(setting.host_num)
    ]
    return hosts

def check_due_packets(hosts, packets_times, t):
    for h in hosts:
        if len(packets_times[h["id"]]) > 0 and packets_times[h["id"]][0] == t:
            packets_times[h["id"]].pop(0)
            h["packet_num"] += 1

def print_history(hosts, setting):
    packets_times = setting.gen_packets()
    for h in hosts:
        # write the timing that the packet is ready to send
        s = ""
        for t in range(setting.total_time):
            if len(packets_times[h["id"]]) > 0 and packets_times[h["id"]][0] == t:
                s += "V"
                packets_times[h["id"]].pop(0)
            else:
                s += " "
        # print the bars
        print(f"    {s}")
        print(f"h{h['id']}: {h['history']}")

def aloha(setting, show_history=False):
    hosts = get_hosts(setting)
    packets_times = setting.gen_packets()
    total_idle_time = 0

    for t in range(setting.total_time):
        history = ["." for i in range(setting.host_num)]\
        
        # check if there is a packet to send
        check_due_packets(hosts, packets_times, t)

        # plan next action for each host
        for h in hosts:
            h["action_to_do"] = h["status"]
            # standby
            if h["status"] == 0:
                # wait
                if h["wait_time"] > 0:
                    h["wait_time"] -= 1
                # plan to send
                elif h["packet_num"] > 0:
                    h["action_to_do"] = 1
                    h["remain_length"] = setting.packet_time

        # perform actions
        for h in hosts:
            h["status"] = h["action_to_do"]

        # check collision
        sending_list = []
        is_idle_time = True
        for h in hosts:
            if h["status"] == 1:
                sending_list.append(h)
                is_idle_time = False
            if history[h["id"]] != ".":
                is_idle_time = False
        if len(sending_list) > 1:
            for h in sending_list:
                h["collision"] = True

        # check whether the channel is idle
        if is_idle_time:
            total_idle_time += 1

        # update host's status and history based on status
        for h in hosts:
            # plan to send
            if h["status"] == 1:
                # start sending case
                if len(h["history"]) == 0 or (h["history"][-1] != "<" and h["history"][-1] != "-"):
                    history[h["id"]] = "<"
                # continue sending case
                else:
                    history[h["id"]] = "-"
                h["remain_length"] -= 1
                # finish sending, check collision
                if h["remain_length"] <= 0:
                    # there is a collision
                    if h["collision"]:
                        h["wait_time"] = random.randint(0, setting.max_collision_wait_time)
                        h["status"] = 0
                        h["collision_num"] += 1
                        history[h["id"]] = "|"
                    # no collision
                    else:
                        h["status"] = 0
                        h["success_num"] += 1
                        h["packet_num"] -= 1
                        history[h["id"]] = ">"
                    # reset collision flag
                    h["collision"] = False
            # record current action
            h["history"] += history[h["id"]]

    # show history
    if show_history:
        print_history(hosts, setting)

    # calculate the result
    total_success_num = sum([h["success_num"] for h in hosts])
    total_success_time = total_success_num * setting.packet_time
    total_collision_time = setting.total_time - total_idle_time - total_success_time
    return (
        total_success_time / setting.total_time,
        total_idle_time / setting.total_time,
        total_collision_time / setting.total_time,
    )

def slotted_aloha(setting, show_history=False):
    hosts = get_hosts(setting)
    packets_times = setting.gen_packets()
    total_idle_time = 0

    for t in range(setting.total_time):
        history = ["." for i in range(setting.host_num)]

        # check if there is a packet to send
        check_due_packets(hosts, packets_times, t)

        # plan next action for each host
        for h in hosts:
            h["action_to_do"] = h["status"]
            # standby
            if h["status"] == 0:
                # wait
                if h["wait_time"] > 0:
                    h["wait_time"] -= 1
                # plan to send
                elif h["packet_num"] > 0 and t % setting.packet_time == 0:
                    h["action_to_do"] = 1
                    h["remain_length"] = setting.packet_time
            # resend with probability p_resend
            elif h["status"] == 2 and t % setting.packet_time == 0:
                if random.random() < setting.p_resend:
                    h["action_to_do"] = 1
                    h["remain_length"] = setting.packet_time

        # perform actions
        for h in hosts:
            h["status"] = h["action_to_do"]

        # check collision
        sending_list = []
        is_idle_time = True
        for h in hosts:
            if h["status"] == 1:
                sending_list.append(h)
                is_idle_time = False
            if history[h["id"]] != ".":
                is_idle_time = False
        if len(sending_list) > 1:
            for h in sending_list:
                h["collision"] = True

        # check whether the channel is idle
        if is_idle_time:
            total_idle_time += 1

        # update host's status and history based on status
        for h in hosts:
            # plan to send
            if h["status"] == 1:
                # start sending case
                if len(h["history"]) == 0 or (h["history"][-1] != "<" and h["history"][-1] != "-"):
                    history[h["id"]] = "<"
                # continue sending case
                else:
                    history[h["id"]] = "-"
                h["remain_length"] -= 1
                # finish sending, check collision
                if h["remain_length"] <= 0:
                    # there is a collision
                    if h["collision"]:
                        h["status"] = 2
                        h["collision_num"] += 1
                        history[h["id"]] = "|"
                    # no collision
                    else:
                        h["status"] = 0
                        h["success_num"] += 1
                        h["packet_num"] -= 1
                        history[h["id"]] = ">"
                    # reset collision flag
                    h["collision"] = False
            # record current action
            h["history"] += history[h["id"]]

    # show history
    if show_history:
        print_history(hosts, setting)

    # calculate the result
    total_success_num = sum([h["success_num"] for h in hosts])
    total_success_time = total_success_num * setting.packet_time
    total_collision_time = setting.total_time - total_idle_time - total_success_time
    return (
        total_success_time / setting.total_time,
        total_idle_time / setting.total_time,
        total_collision_time / setting.total_time,
    )

def csma(setting, one_persistent=False, show_history=False):
    hosts = get_hosts(setting)
    packets_times = setting.gen_packets()
    total_idle_time = 0

    for t in range(setting.total_time):
        history = ["." for i in range(setting.host_num)]

        # check if there is a packet to send
        check_due_packets(hosts, packets_times, t)

        # plan next action for each host
        for h in hosts:
            h["action_to_do"] = h["status"]
            # standby
            if h["status"] == 0:
                # wait
                if h["wait_time"] > 0:
                    h["wait_time"] -= 1
                # plan to send
                elif h["packet_num"] > 0:
                    others_sending = False
                    for others in hosts:
                        if others["id"] == h["id"]:
                            continue
                        # detect others sending
                        if (
                            setting.link_delay >= 0
                            and t > (setting.link_delay + 1)
                            and (
                                others["history"][t - (setting.link_delay + 1)] == "-"
                                or others["history"][t - (setting.link_delay + 1)] == "<"
                            )
                        ):
                            others_sending = True
                            break
                    if not others_sending:
                        h["action_to_do"] = 1
                        h["remain_length"] = setting.packet_time
                    else:
                        if not one_persistent:
                            h["wait_time"] = random.randint(0, setting.max_collision_wait_time)
        
        # perform actions
        for h in hosts:
            h["status"] = h["action_to_do"]

        # check collision
        sending_list = []
        is_idle_time = True
        for h in hosts:
            if h["status"] == 1:
                sending_list.append(h)
                is_idle_time = False
            if history[h["id"]] != ".":
                is_idle_time = False
        if len(sending_list) > 1:
            for h in sending_list:
                h["collision"] = True
        
        # check whether the channel is idle
        if is_idle_time:
            total_idle_time += 1

        # update host's status and history based on status
        for h in hosts:
            # plan to send
            if h["status"] == 1:
                # start sending case
                if len(h["history"]) == 0 or (h["history"][-1] != "<" and h["history"][-1] != "-"):
                    history[h["id"]] = "<"
                # continue sending case
                else:
                    history[h["id"]] = "-"
                h["remain_length"] -= 1
                # finish sending, check collision
                if h["remain_length"] <= 0:
                    # there is a collision
                    if h["collision"]:
                        h["wait_time"] = random.randint(0, setting.max_collision_wait_time)
                        h["status"] = 0
                        h["collision_num"] += 1
                        history[h["id"]] = "|"
                    # no collision
                    else:
                        h["status"] = 0
                        h["success_num"] += 1
                        h["packet_num"] -= 1
                        history[h["id"]] = ">"
                    # reset collision flag
                    h["collision"] = False
            # record current action
            h["history"] += history[h["id"]]

    # show history
    if show_history:
        print_history(hosts, setting)

    # calculate the result
    total_success_num = sum([h["success_num"] for h in hosts])
    total_success_time = total_success_num * setting.packet_time
    total_collision_time = setting.total_time - total_idle_time - total_success_time
    return (
        total_success_time / setting.total_time,
        total_idle_time / setting.total_time,
        total_collision_time / setting.total_time,
    )

def csma_cd(setting, one_persistent=False, show_history=False):
    hosts = get_hosts(setting)
    packets_times = setting.gen_packets()
    total_idle_time = 0

    for t in range(setting.total_time):
        history = ["." for i in range(setting.host_num)]

        # check if there is a packet to send
        check_due_packets(hosts, packets_times, t)

        # plan next action for each host
        for h in hosts:
            h["action_to_do"] = h["status"]
            # standby
            if h["status"] == 0:
                # wait
                if h["wait_time"] > 0:
                    h["wait_time"] -= 1
                # plan to send
                elif h["packet_num"] > 0:
                    others_sending = False
                    for others in hosts:
                        if others["id"] == h["id"]:
                            continue
                        # detect others sending
                        if (
                            setting.link_delay >= 0
                            and t > (setting.link_delay + 1)
                            and (
                                others["history"][t - (setting.link_delay + 1)] == "-"
                                or others["history"][t - (setting.link_delay + 1)] == "<"
                            )
                        ):
                            others_sending = True
                            break
                    if not others_sending:
                        h["action_to_do"] = 1
                        h["remain_length"] = setting.packet_time
                    else:
                        if not one_persistent:
                            h["wait_time"] = random.randint(0, setting.max_collision_wait_time)
            # sending
            elif h["status"] == 1:
                others_sending = False
                for others in hosts:
                    if others["id"] == h["id"]:
                        continue
                    # detect others sending
                    if (
                        setting.link_delay >= 0
                        and t > (setting.link_delay + 1)
                        and (
                            others["history"][t - (setting.link_delay + 1)] == "-"
                            or others["history"][t - (setting.link_delay + 1)] == "<"
                        )
                    ):
                        others_sending = True
                        break
                if others_sending:
                    h["action_to_do"] = 3

        # perform actions
        for h in hosts:
            if h["action_to_do"] == 3:
                h["collision"] = False
                h["remain_length"] = 0
                h["collision_num"] += 1
                h["wait_time"] = random.randint(0, setting.max_collision_wait_time)
                history[h["id"]] = "|"
                h["status"] = 0
            else:
                h["status"] = h["action_to_do"]

        # check collision
        sending_list = []
        is_idle_time = True
        for h in hosts:
            if h["status"] == 1:
                sending_list.append(h)
                is_idle_time = False
            if history[h["id"]] != ".":
                is_idle_time = False
        if len(sending_list) > 1:
            for h in sending_list:
                h["collision"] = True

        # check whether the channel is idle
        if is_idle_time:
            total_idle_time += 1

        # update host's status and history based on status
        for h in hosts:
            # plan to send
            if h["status"] == 1:
                # start sending case
                if len(h["history"]) == 0 or (h["history"][-1] != "<" and h["history"][-1] != "-"):
                    history[h["id"]] = "<"
                # continue sending case
                else:
                    history[h["id"]] = "-"
                h["remain_length"] -= 1
                # finish sending, check collision
                if h["remain_length"] <= 0:
                    # there is a collision
                    if h["collision"]:
                        h["wait_time"] = random.randint(0, setting.max_collision_wait_time)
                        h["status"] = 0
                        h["collision_num"] += 1
                        history[h["id"]] = "|"
                    # no collision
                    else:
                        h["status"] = 0
                        h["success_num"] += 1
                        h["packet_num"] -= 1
                        history[h["id"]] = ">"
                    # reset collision flag
                    h["collision"] = False
            # record current action
            h["history"] += history[h["id"]]

    # show history
    if show_history:
        print_history(hosts, setting)

    # calculate the result
    total_success_num = sum([h["success_num"] for h in hosts])
    total_success_time = total_success_num * setting.packet_time
    total_collision_time = setting.total_time - total_idle_time - total_success_time
    return (
        total_success_time / setting.total_time,
        total_idle_time / setting.total_time,
        total_collision_time / setting.total_time,
    )