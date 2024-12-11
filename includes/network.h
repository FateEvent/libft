#ifndef NETWORKING_H
# define NETWORKING_H

# include <sys/socket.h>		// socket, bind, SOCK_RAW, recvmsg
# include <netdb.h>				// getaddrinfo
# include <arpa/inet.h>			// inet_ntoa, inet_ntop
# include <netinet/ip_icmp.h>	// struct icmphdr
# include <netinet/in.h>		// struct sockaddr_in
# include <sys/types.h>
# include <sys/ioctl.h>
# include <net/if.h>
# include <signal.h>			// sigaction
# include <sys/time.h>			// gettimeofday
# include <errno.h>				// errno
# include "libft.h"

int				parse_ip(char *ip);
int				is_hex(char c);
int				parse_mac(char *mac);
struct in_addr	get_my_ip();

#endif