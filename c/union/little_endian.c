 //Little Endian or Big Endian
 #include<stdio.h>
 union A
 {
	 int x;
 	char y;
 };
 main()
 {
	union A v={1};

	if(v.y==1)
		printf("Little Endian..\n");
	else
		printf("Big Endian..\n");
}
