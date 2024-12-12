#include "networking.h"

unsigned short	compute_checksum(void *packet, int size) {

	unsigned short *buf = packet;
	unsigned int sum = 0;
	unsigned short result;

	for (sum = 0; size > 1; size -= 2)
		sum += *buf++;
	if (size == 1)
		sum += *(unsigned char*)buf;

	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);

	result = ~sum;
	return result;
}
