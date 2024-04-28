#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bookingId=0,sett=0;
 int stations[5]={8,8,8,8,8};
class Passenger
{
private:
    int PNR_Id=bookingId+1;
    int totalTickets,seatNumber;
    char sourceStation;
    char destinationStation;

    public:
    Passenger()
    {

    }
    Passenger(char sourceStation,char destinationStation,int totalTickets,int seatNumber)
    {
        this->sourceStation=sourceStation;
        this->destinationStation=destinationStation;
        this->totalTickets=totalTickets;
        this->seatNumber=seatNumber;
        bookingId+=1;
    }
    int getPNR()
    {
        return PNR_Id;
    }
    setTotalTickets(int canceledTickets)
    {
        totalTickets-=canceledTickets;
    }
    int getTotalTickets()
    {
        return totalTickets;
    }
    char getSourceStation()
    {
        return sourceStation;
    }
    char getDestinationStation()
    {
        return destinationStation;
    }
};
Passenger passengerDetails[20];
int totalPassenger=0;
Passenger waitingList[2];
    int totalWaitList=0,index=0;
class Station
{
private:

    int seat[8]={0};

    int requestedSeatsInWaitingList[2]={0};
    int totalAvailableSeats=8;
    public:
    void bookTickets(char sourceStation,char destinationStation,int totalTickets)
    {

        cout<<totalTickets<<" "<<totalAvailableSeats<<endl;
        if(totalTickets<=totalAvailableSeats)
        {
            cout<<"fsa"<<endl;
            bool check=true;
            for(int i=(sourceStation-'A')+1;i<=destinationStation-'A';i++)
            {
                if(stations[i]<totalTickets)
                {
                    cout<<"false "<<stations[i]<<" "<<totalTickets<<endl;
                    check=false;
                    break;
                }
            }
            if(check)
            {
                if(sett==0){
                Passenger p(sourceStation,destinationStation,totalTickets,8-(sourceStation-'A'));
                 passengerDetails[totalPassenger]=p;
                }
                else{
                    passengerDetails[totalPassenger]=waitingList[index];
                    if(index==0)
                    {
                        waitingList[index]=waitingList[index+1];
                        totalWaitList--;
                    }
                    else{
                        totalWaitList--;
                    }
                }

                cout<<"PNR "<<passengerDetails[totalPassenger].getPNR()<<" is Booked "<<endl;
                totalPassenger++;
                for(int i=sourceStation-'A';i<=destinationStation-'A';i++)
                {
                    stations[i]-=totalTickets;
                    cout<<stations[i]<<" ";
                }
                cout<<endl;
            }
            else if(totalTickets<=2 && totalWaitList<2)
            {
                Passenger p(sourceStation,destinationStation,totalTickets,8-(sourceStation-'A'));
              //  passengerDetails[totalPassenger]=p;
              waitingList[totalWaitList]=p;
                cout<<"PNR "<<waitingList[totalWaitList].getPNR()<<" is Booked IN WL "<<totalWaitList<<endl;
               // totalPassenger++;
               totalWaitList++;

            }
            else{
                cout<<"SEAT IS UNAVAILABLE"<<endl;
            }
        }
    }
    void cancelTickets()
    {
        int PNR_no,canceledTickets;
        cout<<"Enter PNR Number "<<endl;
        cin>>PNR_no;
        cout<<"Enter Tickets To Be Canceled "<<endl;
        cin>>canceledTickets;

        for(int i=0;i<totalPassenger;i++)
        {
            Passenger p=passengerDetails[i];
            if(p.getPNR()==PNR_no)
            {
                p.setTotalTickets(canceledTickets);
                for(int j=p.getSourceStation()-'A';j<=p.getDestinationStation()-'A';j++)
                {
                    stations[j]+=canceledTickets;
                }
                cout<<canceledTickets<<"Tickets From PNR "<<p.getPNR()<<" will be Cancelled"<<endl;
                break;
            }
        }
        for(int i=0;i<totalWaitList;i++)
        {
            Passenger p=waitingList[i];
            Station book;
            index=i;
            sett=1;
            book.bookTickets(p.getSourceStation(),p.getDestinationStation(),p.getTotalTickets());
        }
    }
    void display()
    {
            cout<<setw(5)<<"A"<<setw(5)<<"B"<<setw(5)<<"C"<<setw(5)<<"D"<<setw(5)<<"E"<<endl;
        for(int i=1;i<=8;i++)
        {
            cout<<i<<setw(3);
            for(int j=0;j<5;j++)
            {
                if(i<=8-stations[j])
                {
                    cout<<"*"<<setw(5)<<endl;
                }
            }
            cout<<endl;
        }
    }
};

 void bookTickets()
    {
        Station station;
        char sourceStation,destinationStation;
        int totalTickets;
        cout<<"ENTER SOURCE STATION"<<endl;
        cin>>sourceStation;
        cout<<"ENTER DESTINATION STATION"<<endl;
        cin>>destinationStation;
        cout<<"ENTER NO OF TICKETS"<<endl;
        cin>>totalTickets;
        sett=0;
        station.bookTickets(sourceStation,destinationStation,totalTickets);
    }
int main()
{


      int selectAnyOperations;
      Station station;
    do{
            cout<<"CHOOSE ANY OPERATIONS "<<endl;
    cout<<"1.BOOK TICKET"<<endl;
    cout<<"2.CANCEL TICKET"<<endl;
    cout<<"3.DISPLAY"<<endl;
    cout<<"4.EXIT"<<endl;
    cin>>selectAnyOperations;
    switch(selectAnyOperations)
    {
    case 1:
        bookTickets();
        break;
    case 2:
        station.cancelTickets();
        break;
    case 3:
        station.display();
    }
    }while(selectAnyOperations!=4);
}
