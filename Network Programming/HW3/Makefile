SFTP_USER=c109611066
SFTP_HOSTS=linux1.cs.nycu.edu.tw linux2.cs.nycu.edu.tw linux3.cs.nycu.edu.tw linux4.cs.nycu.edu.tw
SFTP_PATH=/net/course/109/109611066/network-programming-hw2
LOCAL_PATH=.

.PHONY: upload ssh1 ssh2 ssh3 ssh4

upload:
	ssh $(SFTP_USER)@$(word 1,$(SFTP_HOSTS)) "rm -rf $(SFTP_PATH)"
	scp -r $(LOCAL_PATH) $(SFTP_USER)@$(word 1,$(SFTP_HOSTS)):$(SFTP_PATH)

ssh1:
	ssh $(SFTP_USER)@$(word 1,$(SFTP_HOSTS))

ssh2:
	ssh $(SFTP_USER)@$(word 2,$(SFTP_HOSTS))

ssh3:
	ssh $(SFTP_USER)@$(word 3,$(SFTP_HOSTS))

ssh4:
	ssh $(SFTP_USER)@$(word 4,$(SFTP_HOSTS))