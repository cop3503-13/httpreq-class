#include <iostream>
#include <cstdio> //for stream redirect to log file
#include "httpreq.h"
#include "jsonhttpreq.h"

using namespace std;

int main() 
{
	// redirect stderr to error.log
	// std::freopen("error.log", "w", stderr);
	
	/*
	HTTPReq req = HTTPReq(true);
	req.setUrl("http://data.tmsapi.com/v1.1/movies/showings?startDate=2017-03-26&numDays=1&zip=32612&api_key=c7p2t9r6rvqkn4ptxnnu3r5w");
	req.send();
	cout << req.getResponse() << endl;
	
	nlohmann::json JSON = jsonreq.getJSONResponse();
	*/

	JSONHTTPReq jsonreq = JSONHTTPReq();
	jsonreq.setUrl("http://www.alphavantage.co/query?function=SECTOR&apikey=8637");
	jsonreq.send();
	
	cout << jsonreq.getResponse() <<  endl;
	
	nlohmann::json JSON = jsonreq.getJSONResponse();

	cout << JSON["Meta Data"] <<  endl;

	return 0;
}

