// Santa Claus in OS
#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>

class semaphore  //created a binary semaphore which stores either zero or one in the value using class
{
	public:
		int value;
		vector<char> queue; // created a waiting queue for the waiting of raindeer or elves using vector
	
};
void wait(semaphore s,char x) // wait function will hold raindeer or elves in the queue
{
	if(s.value==1)
	{
		s.value=0;
	}
	else
	{
		s.queue.push_back(x); //push the element inside the queue
	}
	
}
char signal(semaphore s) //signal function will remove the raindeer from the queue
{
	if(s.queue.empty()==true)
	{
		s.value=1;
	}
	else
	{
		s.queue.pop_back(); // remove  the last element from the queue
	}
}
class santa // created a santa class which performs santas function
{
	public:
		void wakesanta()
		{
			cout<<"\nwake up santa";
		}
		void prepslade()
		{
			
		
				cout<<"\nsanta is preparing slade";
			
		}
		void gethitched(int x)
		{
			if (x==9)
			{
				cout<<"raindeer are hitched of sleigh";
			}
		}
		
};
void raindeer(semaphore v)
{
	santa c;
	char x;
	static int count=0;
	if(count==9) //if count is equal to 9 then all the raindeer are back from vaccation and wake the santa
	{
		c.wakesanta();
		c.prepslade(); //santa will prepare the slade
		cout<<"\nall the raindeer is comming out of queue"<<endl;
		for(int j=0;j<=count;j++) // all the raindeer will poped out of the waiting queue
		{
			x=signal(v);
		    cout<<'R'<<endl;	
		}
		c.gethitched(count);// get hitched with the slade
		count=0;
	}
	else //if count value is less than 9 then increment it and make the raindeer wait in queue or insert R in queue
	{
		count++;
		wait(v,'R');
		
		
	}
	
}
void elves(semaphore q)
{
	santa b;
	char x;
	static int p=0;
	if(p==3) // if p=3 then all the three elves need santas attention
	{
		b.wakesanta(); // wake the santa
		cout<<"\nelves are ready for santas help\n";
		for(int i=0;i<p;i++)
		{
			x=signal(q);//remove the elves from waiting queue
			cout<<'E'<<endl;
		}
		cout<<"santa is helping the elves";
		p=0;
		
	}
	else // increment the count and make the elf wait in queue until p=3 
	{
		p++;
		wait(q,'E');
	}
	
}
int main()
{
	int x;
	semaphore a,b;
	a.value=0;
	b.value=0;
  for(int i=0;i<=9;i++)
  {
  	raindeer(a);// calling 9 raindeer from southpole to northpole
  }
  for(int i=0;i<=3;i++)
  {
  	elves(a); // elves need santas help
  }
  return 1;
		
}