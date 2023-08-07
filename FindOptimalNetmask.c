#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 8
#define RAND_MAX 4294967295

int breakPointBit=0;

void decimalToBinary(unsigned int n){
	int k;
	for (int i = 31; i >= 0; i--){
		k = n >> i;
		if (k & 1){
			if(i>breakPointBit){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		else{
			if(i>breakPointBit){
				breakPointBit=i;
			}
			printf("0");
		}
	}
}

void main(){
	unsigned int ipAddresses[SIZE];
	unsigned int subnetAddress=RAND_MAX;
	ipAddresses[0]=4294967290;//11111111111111111111111111111010(255.255.255.250)
	ipAddresses[1]=4204967154;//11111010101000101011010011110010(250.162.180.242)
	ipAddresses[2]=4232235777;//11111100010000101100101100000001(252.66.203.1)
	ipAddresses[3]=4232735797;//11111100010010100110110000110101(252.74.108.53)
        ipAddresses[4]=4290934450;//11111111110000100111011010110010(255.194.118.178)
        ipAddresses[5]=4190967291;//11111001110011010001010111111011(249.205.21.251)
        ipAddresses[6]=4292910548;//11111111111000001001110111010100(255.224.157.212)
        ipAddresses[7]=4191964923;//11111001110111000100111011111011(249.220.78.251)
	subnetAddress=RAND_MAX;
	for(int i=0;i<SIZE;i++){
		subnetAddress=~((unsigned int)subnetAddress^(unsigned int)ipAddresses[i]);
        }
	printf("\nResult: (Decimal)%u , (Binary)",subnetAddress);
	decimalToBinary(subnetAddress);
	printf("\n");
}
