#include<iostream>
#include<cstdlib>
using namespace std;
class point
{
	private:
		float x;
		float y;
	public:
		void p_set();
		void p_plot(char arr[][100]);
		void get_xy(float &q, float &z);
		point operator + (point k);
};
class line
{
	private:
		point p1;
		point p2;
	public:
		void get_coor();
		void draw_line(char arr[][100]);
		
};
class triangle
{
	point p1;
	point p2;
	point p3;
	private:
		void draw_line(float x1, float y1, float x2, float y2, char arr[][100]);
	public:
		void get_coor();	
		void draw_triangle(char arr[][100]);	
};
void print_graph(int dmsn,char arr[][100])
{
	int i,j;
	for(i=0;i<dmsn;i++)
	{
		for(j=0;j<dmsn;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
}
void point::p_set()
{
	cout<<"Enter coordinates:"<<endl;				
	cin>>x;
	cin>>y;
}
void point::p_plot(char arr[][100])
{
	int i,j;
	i=x;
	j=y;
	arr[i][j] = '*';
}
void point::get_xy(float &q, float &z)
{
	q=x; z=y;
}
void line::get_coor()
{
	cout<<"enter two points to plot a line"<<endl;
	p1.p_set();
	p2.p_set();
}
void line::draw_line(char arr[][100])
{
	int i,j;
	float x1,y1,x2,y2;
	p1.get_xy(x1,y1);
	p2.get_xy(x2,y2);
	float m = ((y2)-(y1))/((x2)-(x1));
	if(x1>x2)
	{
	
		for(i=x2;i<=x1;i++)
		{
			j = (m*(i-x1))+(y1);
			arr[i][j]='*';
		}	
	}
	else if(x1==x2)
	{
		j=x1;
		if(y1>y2)
		{
			for(i=y2;i<=y1;i++)
			{
				arr[j][i]=='*';
			}
		}
		else
		{
			for(i=y1;i<=y2;i++)
			{
				arr[j][i]='*';
			}
		}
	}
	else
	{
		for(i=x1;(i<=x2);i++)
		{
			j = (m*(i-x1))+(y1);
			arr[i][j]='*';
		}
	}
}
void triangle::get_coor()
{
	cout<<"enter three points to plot a triangle"<<endl;
	p1.p_set();
	p2.p_set();
	p3.p_set();
}
void triangle::draw_line(float x1, float y1, float x2, float y2, char arr[][100])
{
	int i,j;
	
	//float x1,y1,x2,y2;
	//p1.get_xy(x1,y1);
	//p2.get_xy(x2,y2);
	float m = ((y2)-(y1))/((x2)-(x1));
	if(x1>x2)
	{
	
		for(i=x2;i<=x1;i++)
		{
			j = (m*(i-x1))+(y1);
			arr[i][j]='*';
		}	
	}
	else if(x1==x2)
	{
		j=x1;
		if(y1>y2)
		{
			for(i=y2;i<=y1;i++)
			{
				arr[j][i]=='*';
			}
		}
		else
		{
			for(i=y1;i<=y2;i++)
			{
				arr[j][i]='*';
			}
		}
	}
	else
	{
		for(i=x1;(i<=x2);i++)
		{
			j = (m*(i-x1))+(y1);
			arr[i][j]='*';
		}
	}
}
void triangle::draw_triangle(char arr[][100])
{
	//int i,j;
	float x1,y1,x2,y2,x3,y3;
	p1.get_xy(x1,y1);
	p2.get_xy(x2,y2);
	p3.get_xy(x3,y3);
	draw_line(x1,y1,x2,y2,arr);
	draw_line(x2,y2,x3,y3,arr);
	draw_line(x3,y3,x1,y1,arr);
}
int main()
{
	char a[100][100];
	int n,i,j,choice;
	cout<<"Enter the dimensions"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			a[i][j]='-';
	}
	point p[100];
	line l;
	triangle t;
	while(1)
	{
		cout<<"What you want to draw\n1. Point\n2. Line\n3. Triangle\n4. exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			
				int k;
				cout<<"How many points do you want to plot?"<<endl;
				cin>>k;
				for(i=0;i<k;i++)
					p[i].p_set();
				for(i=0;i<k;i++)
					p[i].p_plot(a);
			break;
			case 2:
				l.get_coor();
				l.draw_line(a);
			break;
			case 3:
				t.get_coor();
				t.draw_triangle(a);
				break;
			case 4:
				exit(0);
		}
		print_graph(n,a);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i][j]='-';
		}
	}

	
	
	
}
