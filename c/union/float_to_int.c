 #include<stdio.h>
 union A
 {
	 int x;
	float y;
 };

 main()
{
	 int i;
	 union A v;
	 v.y=7.5;
	 for(i=31;i>=0;i--)
		 printf("%d",v.x>>i & 1);
 }
