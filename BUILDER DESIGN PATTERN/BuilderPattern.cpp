//when we create object using constructor, constructor gets overloaded.
//Here we write code such that whenever someone want to make object of HTTPReq, they shouldnot use HTTPReq class, i.e shouldnot do
// HTTPReq* req=new HTTPReq()
//For doing this we usually make constructor private(as done in singleton Design pattern)
//So now no one can use construtor to create new object and no constructor overloading happens.
// we use friend class , this class has access to private members of the Main class.


#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
#include<map>

using namespace std;

class HttpRequest{
  private:
  string url;
  string method;
  map<string,string>headers;
  map<string,string>queryParams;
  string body;
  int timeout;

  //PRIVATE CONSTRUCTOR ONLY CAN BE ACCESSED BY THE BUILDER
  HttpRequest() {}

  public:
  friend class HttpRequestBuilder;
  // Method to execute the HTTP request
    void execute() {
        cout << "Executing " << method << " request to " << url << endl;
        
        if (!queryParams.empty()) {
            cout << "Query Parameters:" << endl;
            for (const auto& param : queryParams) {
                cout << "  " << param.first << "=" << param.second << endl;
            }
        }

        cout << "Headers:" << endl;
        for (const auto& header : headers) {
            cout << "  " << header.first << ": " << header.second << endl;
        }
        
        if (!body.empty()) {
            cout << "Body: " << body << endl;
        }
        
        cout << "Timeout: " << timeout << " seconds" << endl;
        cout << "Request executed successfully!" << endl;
    }
};

class HttpRequestBuilder {
  private:
  HttpRequest req;
  public:
  public:    
    // Method chaining
    HttpRequestBuilder& withUrl(const string& u) {
        req.url = u; 
        return *this;
    }

    HttpRequestBuilder& withMethod(string method) {
        req.method = method;
        return *this;
    }
    
    HttpRequestBuilder& withHeader(const string& key, const string& value) {
        req.headers[key] = value;
        return *this;
    }

    HttpRequestBuilder& withQueryParams(const string& key, const string& value) {
        req.queryParams[key] = value;
        return *this;
    }
    
    HttpRequestBuilder& withBody(const string& body) {
        req.body = body;
        return *this;
    }
    
    HttpRequestBuilder& withTimeout(int timeout) {
        req.timeout = timeout;
        return *this;
    }

    // Build method to create the immutable HttpRequest object
    HttpRequest build() {
        // Validation logic can be added here
        if (req.url.empty()) {
            throw runtime_error("URL cannot be empty");
        }
        return req;
    }
};

int main() {
    // Using Builder Pattern (nested class)
    HttpRequest request = HttpRequestBuilder()
        .withUrl("https://api.example.com")
        .withMethod("POST")
        .withHeader("Content-Type", "application/json")
        .withHeader("Accept", "application/json")
        .withQueryParams("key", "12345")
        .withBody("{\"name\": \"Aditya\"}")
        .withTimeout(60)
        .build();

    request.execute(); // Guaranteed to be in a consistent state
}
