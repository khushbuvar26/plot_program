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
		cout<<"What you want to draw\n1. Point\n2. Line\n3. exit"<<endl;
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
