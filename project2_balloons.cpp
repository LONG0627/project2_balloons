#include<stdio.h>
#include<string.h>
#include<math.h>
const double pi=acos(-1.0);
int n,x1,y11,z1,x2,y2,z2,vis[10],dis[10];
double r[10],vol,max;
int abs(int a)
{
	if(a<0)
		return 0-a;
	return a;
}
struct
{
	int x,y,z;
}p[10];
int min2(int a,int b)
{
	return a<b?a:b;
}
int min3(int a,int b,int c)
{
	return min2(a,min2(b,c));
}
void solve(int k)
{
	int i,j,flag;
	if(k==n)
	{
		if(vol>max)
			max=vol;
	}
	else
		for(i=0;i<n;i++)
			if(!vis[i])
			{
				flag=0;
				r[i]=1000000001;
				for(j=0;j<n;j++)
					if(vis[j])
					{
						double d=sqrt((double)(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)+(p[i].z-p[j].z)*(p[i].z-p[j].z))-r[j];
						if(d<0)
						{
							flag=1;
							break;
						}
						if(r[i]>d)
							r[i]=d;
					}
				vis[i]=1;
				if(flag)
					r[i]=0;
				else
					if(r[i]>dis[i])
						r[i]=dis[i];
				vol+=4*pi*r[i]*r[i]*r[i]/3;
				solve(k+1);
				vol-=4*pi*r[i]*r[i]*r[i]/3;
				vis[i]=0;
			}
			
}
int main()
{
	int i,cnt=1;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d%d%d%d%d%d",&x1,&y11,&z1,&x2,&y2,&z2);
		for(i=0;i<n;i++)
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		for(i=0;i<n;i++)
			dis[i]=min2(min3(abs(p[i].x-x1),abs(p[i].x-x2),abs(p[i].y-y11)),min3(abs(p[i].y-y2),abs(p[i].z-z1),abs(p[i].z-z2)));
		vol=max=0;
		memset(vis,0,sizeof(vis));
		solve(0);
		printf("Box %d: %.0f\n\n",cnt++,(double)abs(x1-x2)*abs(y11-y2)*abs(z1-z2)-max);
	}
	return 0;
}
