	#include <stdio.h>
	#include <string.h> // for strlen() and snprintf
	#include <mqueue.h> // for mq_open,mq_close,mq_attr(settings) . mqmq -> message queue.
	#include <fcntl.h> // for file controls like O_CREAT 0_RDONLY O_WRONLY O(option) 0_RDWR
	#include <sys/stat.h>  // status or Persmission like 0644 where 0 tell its octal not normal
	
	int main(void){
		
		struct mq_attr attr = {
			.mq_maxmsg = 10,
			.mq_msgsize = 64
		};

		mqd_t q = mq_open(
				"/arslan_q",
				O_CREAT | O_WRONLY ,
				0644,
				&attr
		);

		if ( q == (mqd_t) -1 ){
			perror("mq_open");
			return 1;
		}
		
		char msg[64];

		for(int i = 0 ; i < 5 ; i++) {
			
			snprintf( msg, sizeof(msg),"Hello this is message %d\n in mailbox",i+1);
		
			if(mq_send(q, msg, strlen(msg)+1,0) == (mqd_t) -1 ){
				perror("mq_send");
				break;
			}
			printf("sent : %s\n", msg);
		}

		mq_close(q);
		return 0;
	}


			




