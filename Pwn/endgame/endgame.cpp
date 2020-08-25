#include<bits/stdc++.h>
#include<unistd.h>

#define ll long long
using namespace std;
//ADD a flag for exiting the game

//STORE
void store(ll &bal,ll &th,ll &level,ll &day,int &f)
{
	int o;
    cout<<"-------------------------------\nWelcome to Stark Industries:";
    cout<<"\n-------------------------------\nLevel 1 Suit: 10 Damage\nPrice: Rs.10\n-------------------------------\nLevel 2 Suit: 100 Damage\nPrice: Rs.100\n-------------------------------\nLevel 3 Suit: 1,000 Damage\nPrice: Rs.1,000\n-------------------------------\nLevel 4 Suit: 10,000 Damage\nPrice: Rs.1,000,000\n-------------------------------\nLevel 5 Suit: 100,000 Damage\nPrice: Rs.1,000,000,000\n-------------------------------\n";
    cout<<"What do you want? (1-5 or 0 for exit) >";
    cin>>o;
    
    switch(o){
    	case 1:
    		if(bal>=10){
    		level=o;
			cout<<"Received Spiderman Suit "<<level<<"."<<endl;
			bal-=10;}
			else cout<<"Not enough balance .Earn more!!!\n\n";
			break;
		case 2:
    		if(bal>=100){
    		level=o;
			cout<<"Received Spiderman Suit "<<level<<"."<<endl;
			bal-=10;}
			else cout<<"Not enough balance .Earn more!!!\n\n";
			break;
		case 3:
    		if(bal>=1000){
    		level=o;
			cout<<"Received Spiderman Suit "<<level<<"."<<endl;
			bal-=1000;}
			else cout<<"Not enough balance .Earn more!!!\n\n";
			break;
		case 4:
    		if(bal>=10000){
    		level=o;
			cout<<"Received Spiderman Suit "<<level<<"."<<endl;
			bal-=10000;}
			else cout<<"Not enough balance .Earn more!!!\n\n";
			break;
		case 5:
    		if(bal>=1000000000){
    		level=o;
			cout<<"Received Iron-Spider Suit "<<level<<"."<<endl;
			bal-=1000000000;}
			else cout<<"Not enough balance .Earn more!!!\n\n";
			break;
		case 0:
		    cout<<"EXITTING";
		    f=0;
		    break;
		default:
		    cout<<"invalid input :("<<endl;
		    f=0;
			
	}
	th+=6;
	if(th>=24)
	{
		th-=24;
		day++;
		level--;
		cout<<"You got infinity gauntlet.";
	}
    
    
}

//WORK
void work(ll &bal,ll &th,ll &level,ll &day,int &f){
	cout<<"-------------------------------\nGoing to work...\nTime passes...\nSlowly...\n-------------------------------\n";
	string s;
	cout<<"Tony Stark wants to know how many hours you worked: >";
	cin>>s;
	if(s.length()>3)
	cout<<"Only 3 characters allowed\n-------------------------------\n";
	
	else if(s.length()<=2){
	    
		bal+=stoi(s);
		cout<<s<<" hours at Rs.1/hour? That's Rs."<<s<<".0\n";
		cout<<"Rs."<<s<<" received. \n";
	}
	else if(s.length()==3){
	    if(s[1]=='e')
	    {
	       string a="",b="";
	       a+=s[0];b+=s[2];
	       int a1=stoi(a),b1=stoi(b);
	       ll num=a1*pow(10,b1);
	       bal+=num;
	       cout<<num<<" hours at Rs.1/hour? That's Rs."<<num<<".0\n";
		   cout<<"Rs."<<num<<" received. \n";
	    }
	    else
	    {
	    	ll num=stoi(s);
	    	bal+=num;
	       cout<<num<<" hours at Rs.1/hour? That's Rs."<<num<<".0\n";
		   cout<<"Rs."<<num<<" received. \n";
		}
	}
	th+=6;
	if(th>=24)
	{
		th-=24;
		day++;
		level--;
	}
	
	
	
}

//Infinity War
void cave(ll &bal,ll &th,ll &level,ll &day, int &f){
	cout<<"Welcome to the Titan - Thanos's Planet\n-------------------------------\n";
	if(level<5)
	{
		cout<<"You fought with Thanos and tried to stop him using power stone.";
		cout<<"\nBut he is still more powerful than your web shooters.";
		cout<<"\n He kills you.";
		cout<<"\nGame over\n-------------------------------\n";
		f=0;
	}
	else if(level==5)
	{
		cout<<"This time you have Tony Stark and other Avengers .";
		cout<<"\nBut Thanos destroys Iron Man's Armour using Power Stone.";
		cout<<"\nYour Iron-Spider Suit is also weak against him.";
		cout<<"\n Beating all of you, he collects all stones and snaps.";
		cout<<"\n50 percent of the world's population starts vanishing including your team.";
		cout<<"\n We are in the ENDGAME now.";
		cout<<"\nGame over\n-------------------------------\n";
		f=0;
	}
	else if(level>=6)
	{
		cout<<"You time travelled one day back when Avengers lost.";
		cout<<"\nYou got the most powerful thing,";
		cout<<"\nCarrying Infinity Gauntlet, you walk over to Iron Man";
		cout<<"\nYou're still dizzy from the time travelling.";
		cout<<"\nAs the only way to save the universe, Iron Man aka Tony Stark wields Infinity Gauntlet.";
		cout<<"\nAs if by magic, his hands start glowing, and he snaps.";
		cout<<"\nWhole Thanos Army vanishes, with Thanos.";
		cout<<"\nYou - We won Mr.Stark.";
		cout<<"\nWorld Peace restored.\n";
		cout<<"\npCTF{wh473ver_17_t4k3s}"
		f=0;
	}
	
	
}

//HOME
void home(ll &bal,ll &th,ll &level,ll &day,int &f)
{
	
	
	ll d;
	cout<<"Your home.\nHere you can take a rest.\nPlease note: Your suit degrade by level 1 per day.\n";
	cout<<"How many days do you want to rest for? > ";
	cin>>d;
	cout<<"Sleeping for "<<d<<" days\n";
	if(level!=0 && d>=0){
	
	cout<<"Your suit in storage has degraded from "<<level<<" to "<<level-d<<"\nYou woke up well rested.";
	level-=d;
	
	
	}
	else if(level==5){
	
	cout<<"Your suit in storage has degraded from "<<level<<" to "<<level-d<<"\nYou woke up well rested.";
	level-=d;
	
	
	}
	
	else
	cout<<"You woke up well rested. And your suit did not degraded as you dont have one :(\n";
	day+=d;
	
	

	
}

//STORAGE
// void storage(ll &bal,ll &th,ll &level,ll &day)
// {
// 	cout<<"-------------------------------\nStorage for up to (1) sword.\nPlease note: Swords degrade by 1 level for each day they are left in storage.\n-------------------------------\n";
// 	if(level!=0)
// 	{
// 		cout<<"Storage contains a sword level "<<level<<endl;
// 		char c;
// 		cout<<"Do you want to take the sword out? (y/n) > ";
// 		cin>>c;
		
// 	}
// }
	



int main(){
    
    cout<<"Welcome to Marvel Avengers!";
    cout<<"\nWe're glad Spiderman decided to help us fight the Thanos and bring back peace to the universe.\n";
    cout<<"\nMr. Stark will help to get you some suit for your fight!";
    cout<<"\nThere's also Stark Industries for you to intern at. Mr. Stark is a very trusting guy, don't try to scam him please.";
    cout<<"\n\n-------------------------------\n";
    ll bal=0,day=0,th=0,option,level=0,n=0;
    int f=1;
    while(true)
    {
        cout<<"-------------------------------\n";
        cout<<"Day: "<<day<<endl;
        cout<<"Time: "<<th<<":"<<"00"<<endl;
        cout<<"Your balance: Rs."<<bal<<".00"<<endl;
        if(level!=0)
        cout<<"Your suit: "<<level<<endl;
        cout<<"-------------------------------\n";
        cout<<"1: Go to Mr. Stark\n2: Go to work\n3: Go to Titan\n4: Go home\n>";
        cin>>option;
        
        switch(option){
            case 1:
                store(bal,th,level,day,f);
                break;
            case 2:
            	work(bal,th,level,day,f);
            	break;
            case 3:
            	cave(bal,th,level,day,f);
            	break;
            case 4:
            	home(bal,th,level,day,f);
				break;
			default:
			    cout<<"invalid input :( \n EXITTING";
			    f=0;
        }
        if(f==0)
        break;
        
    }
    
}
