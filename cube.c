//! Расставить в вершинах куба числа от 1 до 8, чтобы суммы по всем граням были разными

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int v[8];
    if (argc<9){
	if (argc!=2) {
	printf("Usage: ./cube a b c d e f g h\n");
	printf("   b---c       \n");
	printf("  /|  /|       \n");
	printf(" a-+-d |       \n");
	printf(" | f-|-g       \n");
	printf(" |/  |/        \n");
	printf(" e---h         \n");
	return -1;
	}
	else {
	    for (int k=0;k<8;k++)
	    {
		v[k]=argv[1][k]-'0';
	    }
	}
    }
    else {
        for (int i=0;i<8;++i)
	{
	    v[i]=atoi(argv[i+1]);
        }
    }
    int f[6];
    f[0]=v[0]+v[1]+v[2]+v[3];
    f[1]=v[3]+v[2]+v[6]+v[7];
    f[2]=v[4]+v[5]+v[6]+v[7];
    f[3]=v[0]+v[1]+v[4]+v[5];
    f[4]=v[5]+v[1]+v[2]+v[6];
    f[5]=v[0]+v[3]+v[4]+v[7];

	printf("cube:\n");
	printf("        %d    %d        \n",f[0],f[4]);
	printf("        ^    ^        \n");
	printf("        |   /         \n");
	printf("      %d---%d       \n",v[1],v[2]);
	printf("     /|  /|       \n");
	printf("    %d-+-%d | ->%d      \n",v[0],v[3],f[1]);
	printf("%d<-| %d-|-%d       \n",f[3], v[5],v[6]);
	printf("    |/  |/        \n");
	printf("    %d---%d         \n",v[4],v[7]);
	printf("   /  |            \n");
	printf("  V   v            \n");
	printf(" %d   %d            \n",f[5],f[2]);

    int ans=1;
    for (int i=0;i<6;++i)
	for (int j=0;j<6;j++) {
	    if (i!=j && f[i]==f[j]) {
		ans=0;
		break;
	    }
	}
    if (ans) printf("OK!\n");
    else printf("FAIL!\n");
    return 0;
}