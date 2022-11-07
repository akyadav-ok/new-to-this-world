#include <iostream>

using namespace std;

class Matrix
{
	private:
		int** tmat;
		int size;
		
	public:
		Matrix(int t,int s)
		{
			size=s;
			if(t==1)					//matrix is upper triangular
			{
				tmat=new int*[size];
				for(int i=0;i<size;i++)
				{
					tmat[i]=new int[size-1];
				}
			}
			else if(t==2)
			{
				tmat=new int*[size];
				for(int i=0;i<size;i++)
				{
					tmat[i]=new int[i+1];
				}
			}
		}
		void fill(int t)
		{
			if(t==1)
			{
				for(int i=0;i<size;i++)
				{
					for(int j=i;j<size;j++)
					{
						cout<<"Element ["<<i<<","<<j<<"] : ";
						cin>>tmat[i][j];
					}
				}
			}
			if(t==2)
			{
				for(int i=0;i<size;i++)
				{
					for(int j=0;j<=i;j++)
					{
						cout<<"Element ["<<i<<","<<j<<"] : ";
						cin>>tmat[i][j];
					}
				}
			}
			cout<<endl;
		}
		void display(int t)
		{
			if(t==1)
			{
				for(int i=0;i<size;i++)
				{
					for(int j=1;j<=i;j++)
					{
						cout<<"0 ";
					}
					for(int j=i;j<size;j++)
					{
						cout<<tmat[i][j]<<" ";
					}
					cout<<endl;	
				}
			}
			if(t==2)
			{
				for(int i=0;i<size;i++)
				{
					for(int j=0;j<=i;j++)
					{
						cout<<tmat[i][j]<<" ";
					}
					for(int j=size-i;j>1;j--)
					{
						cout<<"0 ";
					}
					cout<<endl;	
				}
			}
		}
};

int main()
{
	int type,s;
	cout<<"Enter type of array (1.Upper Triangular/2.Lower Triangular) : ";
	cin>>type;
	cout<<"Enter size : ";
	cin>>s;
	Matrix mat(type,s);
	mat.fill(type);
	mat.display(type);
}
