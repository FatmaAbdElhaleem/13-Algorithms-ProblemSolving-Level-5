#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "clsDate.h"

class clsQueueLine
{
private:
	string _Prefix;
	short _AvgServeTime;
	short _TotalTickets = 0;

	class clsTicket
	{
	private:
		short _Number=0;
		string _Prefix="";
		string _TicketDateTime="";
		short _ExpectedServeTime=0;
		short _AvgServeTime=0;
		short _WaitingClients=0;
	public:
		clsTicket(short Number, string Prefix, short AvgServeTime, short WaitingClients)
		{
			_Number = Number;
		    _Prefix = Prefix;
			_TicketDateTime = clsDate::GetSystemDateTimeString();
		    _AvgServeTime = AvgServeTime;
			_WaitingClients = WaitingClients;
			_ExpectedServeTime = ExpectedServeTime();
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		short ExpectedServeTime()
		{
			return (_AvgServeTime * _WaitingClients);
		}

		short Number()
		{
			return _Number;
		}
		string Prefix()
		{
			return _Prefix;
		}

		string FullNumber()
		{
			return (_Prefix+to_string(_Number));
		}

		string TicketDateTime()
		{
			return _TicketDateTime;
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketDateTime;
			cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";
		}
	};

public:
	queue<clsTicket> QueueLine;
	clsQueueLine(string prefix, short AvgServeTime)
	{
		_Prefix = prefix;
		_AvgServeTime = AvgServeTime;
		_TotalTickets = 0;
	}
	void IssueTicket()
	{
		_TotalTickets++;
		QueueLine.push(clsTicket(_TotalTickets, _Prefix, _AvgServeTime, WaitingClients()));
	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	short ServedClients()
	{
		return (_TotalTickets-WaitingClients());
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n\n";

	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Clients left!";

		return QueueLine.front().FullNumber();
	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		queue <clsTicket> TempQueueLine = QueueLine;
		while (!TempQueueLine.empty())
		{
			cout << " " << TempQueueLine.front().FullNumber() <<" <-- ";
			TempQueueLine.pop();
		}
		cout << endl;
	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			cout << TempStackLine.top().FullNumber() << " --> ";
			TempStackLine.pop();
		}
		cout << endl;
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		queue <clsTicket> TempQueueLine=QueueLine; 
		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print() ;
			TempQueueLine.pop();
		}
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

		QueueLine.pop();
		return true;
	}
};