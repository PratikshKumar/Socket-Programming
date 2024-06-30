/*
    sudo apt-get update
sudo apt-get install -y libboost-all-dev

g++ -o server server.cpp -lboost_system -lboost_thread -pthread
./server

*/










#include <iostream>
#include <boost/asio.hpp>
using namespace std;
// using namespace boost;

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
        
        std::cout << "Server started. Waiting for connections..." << std::endl;
        
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        
        std::cout << "Client connected." << std::endl;
        
        std::string message = "Hello from server";
        boost::system::error_code ignored_error;
        boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
