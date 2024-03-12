# Precondition: None
# Postcondition: Return the hosts in string, 
#                separated by space.
def get_hosts():
    command = 'h1 h2 h3 h4 h5 h6 h7 h8'
    return command

# Precondition: None
# Postcondition: Return the switches in 
#                string, separated by space.
def get_switches():
    command = 's1 s2 s3 s4 s5 s6 s7'
    return command

# Precondition: None
# Postcondition: Return the ip addresses of 
#                each host, using a dictionary.
#                The key is the host name, and
#                the value is the ip address.
def get_ip():
    ip_dict = dict()
    ip_dict['h1'] = 'h1ip'
    ip_dict['h2'] = 'h2ip'
    ip_dict['h3'] = 'h3ip'
    ip_dict['h4'] = 'h4ip'
    ip_dict['h5'] = 'h5ip'
    ip_dict['h6'] = 'h6ip'
    ip_dict['h7'] = 'h7ip'
    ip_dict['h8'] = 'h8ip'
    return ip_dict

# Precondition: None
# Postcondition: Return the mac addresses of
#                each host, using a dictionary.
#                The key is the host name, and
#                the value is the mac address.
def get_mac():
    mac_dict = dict()
    mac_dict['h1'] = 'h1mac'
    mac_dict['h2'] = 'h2mac'
    mac_dict['h3'] = 'h3mac'
    mac_dict['h4'] = 'h4mac'
    mac_dict['h5'] = 'h5mac'
    mac_dict['h6'] = 'h6mac'
    mac_dict['h7'] = 'h7mac'
    mac_dict['h8'] = 'h8mac'
    return mac_dict

# Precondition: None
# Postcondition: Return the links between
#                the hosts and switches.
#                The format is 'a,b' where 
#                a is the source node and b is
#                the destination node.
def get_links():
    command = 'h1,s1 h2,s1 h3,s3 h4,s3 h5,s4 h6,s4 h7,s6 h8,s6 s1,s2 s3,s2 s4,s5 s6,s5 s2,s7 s5,s7'
    return command