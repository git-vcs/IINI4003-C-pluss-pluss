#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             // If not error:
                             if (!ec) {
                                 // Retrieve message from client as string:
                                 istream read_stream(read_buffer.get());
                                 std::string message;
                                 getline(read_stream, message);
                                 message.pop_back(); // Remove "\r" at the end of message

                                 // Close connection when "exit" is retrieved from client
                                 if (message == "exit")
                                     return;


                                 cout << "Message from a connected client: " << message << endl;
                                 cout << "client url-request: " <<message.size()<< endl;
                                 std::string html_start="<!DOCTYPE html><html><body>";
                                 std::string html_end="</body></html>";

                                 std::string html_body;
                                 if(message == "GET / HTTP/1.1"){
                                     html_body ="<h1>Dette er hovedsiden</h1>";
                                 }else if(message=="GET /en_side HTTP/1.1"){
                                     html_body ="<h1>Dette er en side</h1>";
                                 }else {
                                     html_body ="<h1>404 not found</h1>";
                                 }


                                 auto write_buffer = make_shared<boost::asio::streambuf>();
                                 ostream write_stream(write_buffer.get());

                                 // Add message to be written to client:
                                 write_stream <<"HTTP/1.1 200 OK"<<"\r\n"<<

                                 "Content-Type: text/html; charset=UTF-8"<<"\r\n"
                                 "Content-Length: "<<html_body.size()+html_start.size()+html_end.size()<<"\r\n\r\n"<<
                                 html_start<<html_body<<html_end<<"\r\n";

                                 // Write to client
                                 async_write(connection->socket, *write_buffer,
                                             [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                                 // If not error:
                                                 if (!ec)
                                                     handle_request(connection);
                                             });
                             }
                         });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            // If not error:
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();

        io_service.run();
    }
};

int main() {
    EchoServer echo_server;

    cout << "Starting echo server" << endl
         << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection." << endl;

    echo_server.start();
}
