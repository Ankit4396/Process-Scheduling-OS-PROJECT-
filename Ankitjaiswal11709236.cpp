#include<bits/stdc++.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int OS(){
	int n,z=0,z1=0,z2=0,at=0,T=0;
	string s1;
	cout<<" \t \t ________WELCOME TO THE PROCESS SCHEDULING ____________"<<endl;
	cout<<"Enter the no of process : ";
	cin>>n;
	string ipp[n],ipp1[n],ipp2[n];
	int art[n],art2[n],bst[n],art1[n],bst1[n],bst2[n],agar[n];
	queue<string>q,qo,wait2;
	queue<int>bo;
	queue<string>final,wait,wait1;
	system("CLS");
	cout<<" \t \t ________WELCOME TO THE PROCESS SCHEDULING ____________"<<endl;
	for(int i=0;i<n;i++){
		cout<<"                                   kindly enter the following details:-                          "<<endl;
	cout<<"_____________________________________________________________________________________________________"<<endl;
		cout<<"Enter the process name : ";
		cin>>ipp[i];
		cout<<"Enter the Arrival time of process ' "<<ipp[i]<<" ' :";
		cin>>art[i];
		art1[i]=art[i];	
		agar[i]=art[i];
		cout<<"Enter the Burst time of process ' "<<ipp[i]<<" ' :";
		cin>>bst[i];
		at+=bst[i];
		system("CLS");
	}
	cout<<" \t \t ________WELCOME TO THE PROCESS SCHEDULING ____________"<<endl;
	cout<<"  Your Data entered successfully and saved   "<<endl;
	cout<<" Kindly  press ENTER to continue the program "<<endl;
	system("PAUSE");
	system("CLS");
	cout<<" \t \t ________WELCOME TO THE PROCESS SCHEDULING ____________"<<endl;
	cout<<"  \t \t \t DATA YOU HAVE ENTERED: "<<endl; 
	cout<<"__________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<"Process Name"<<"|"<<setw(10)<<"|"<<"Arival Time"<<"|"<<setw(10)<<"|"<<"Burst Time"<<"|"<<endl;
	for(int j=0;j<n;j++)
	{
	cout<<"\t"<<"___________________________________________________________________________________"<<endl;
	cout<<"\t"<<" "<<ipp[j]<<setw(25)<<" "<<art[j]<<setw(23)<<" "<<bst[j]<<" "<<endl;
	}
	stable_sort(art1,art1+n);
	for(int g=0;g<n;g++){
		for(int f=0;f<n;f++){
			if(art1[g]==art[f]){
				ipp1[g]=ipp[f];
				art[f]=-1;
				q.push(ipp1[g]);
				
				bst1[g]=bst[f];
				
			}
		}
	}
	cout<<endl;
	cout<<"  \t \t \t    DATA SORTED ACCORDING TO THE ARRIVAL TIME : "<<endl; 
	cout<<"__________________________________________________________________________________"<<endl;
	cout<<"\t"<<"|"<<"Process Name"<<"|"<<setw(10)<<"|"<<"Arival Time"<<"|"<<setw(10)<<"|"<<"Burst Time"<<"|"<<endl;
	for(int x=0;x<n;x++)
	{
	cout<<"\t"<<"___________________________________________________________________________________"<<endl;
	cout<<"\t"<<" "<<ipp1[x]<<setw(25)<<" "<<art1[x]<<setw(23)<<" "<<bst1[x]<<" "<<endl;
	}
	//Robin Round method for 6 quantum time;
	while(!q.empty()){
		
		
		if(bst1[z]>0){
			bst1[z]-=6;
			
			if(bst1[z]<=0){
				T=bst[z]+6;
				art1[z]=-1;
				final.push(q.front());
				
				q.pop();
			}
			else{
				T+=6;
				wait.push(q.front());
				q.pop();
			}
		}
		z++;
	}

	//Round Robin method for 10 quantum time;
	while(!wait.empty()){
		if(bst1[z1]>0){
			bst1[z1]-=10;
			if(bst1[z1]<=0){
				T=bst1[z1]+10;
				art1[z1]=-1;
				final.push(wait.front());
				wait.pop();
			}
			else{
				T+=10;
				wait1.push(wait.front());
				wait.pop();
			}
		}
		z1++;
	}
	
	for(int r=0;r<n;r++){
		bst2[r]=bst1[r];
	}
	stable_sort(bst2,bst2+n,greater<int>());

	for(int g3=0;g3<n;g3++){
		for(int f3=0;f3<n;f3++){
			if(bst2[g3]==bst1[f3]){
				ipp2[g3]=ipp1[f3];
				bst1[f3]=0;
				wait2.push(ipp2[g3]);
				
				art2[g3]=art1[f3];
				
			}
		}
	}

		
		// FIFO USING GREATER BURST TIME

		if(at<T){
			for(int h=0;h<n;h++){
				if(bst2[h]>0){
					final.push(ipp2[h]);
				}
			}
		}
		//at>T 
		else{
			for(int v=0;v<n;v++){
				if(art2[v]!=-1 && art[2]<=T){
					qo.push(ipp2[v]);
					bo.push(bst2[v]);
				}
				
				int yi=bo.size();
				string zx[yi];
				int d[bo.size()],d1[bo.size()];
				while(!qo.empty() || !bo.empty()){
					for(int v1=0;v1<qo.size();v1++){
						zx[v1]=qo.front();
						qo.pop();
						d[v1]=bo.front();
						d1[v1]=bo.front();
						bo.pop();
						
					}
				}
				stable_sort(d1,d1+yi,greater<int>());
				for(int l=0;l<yi;l++){
					for(int l1=0;l1<yi;l1++){
						if(d1[l]==d[l1]){
							final.push(zx[l1]);
						}
					}
				}
			}
			
		}
				
	
     cout<<"  __________SEQUENCE IN WHICH THE PROCESS COMPLETED ___________  :"<<endl;
     cout<<"< ";
     int size=final.size();
	 while(!final.empty()){
     	
     	cout<<final.front();
     		if(size>1){
     		cout<<" , ";
		 }
		 size--;
     	final.pop();
	 }
	 cout<<" >";
	

	
}
int main(){
	
	OS();
	
}
