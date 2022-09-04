#include <iostream>
#include <boost/asio.hpp>

int checkConnection(std::string addr, std::string port)
{
    boost::asio::ip::tcp::iostream stream(addr, port);
    if (!stream)
    {
        return -1;
    }
    else
    {
        return atoi(port.c_str());
    }
}

int main()
{
    std::cout << "PortScanner\n";
    std::cout << "version 0.0.1\n";
    std::cout << "============================\n";
    std::cout << "You can enter a single port or a range of ports separated by a dash\n";
    std::cout << "For example:\n";
    std::cout << "\"Enter port: 8080\" ";
    std::cout << "Or ";
    std::cout << "\"Enter port: 0-65536\"\n";
    std::cout << "============================\n";

    while (true)
    {
        std::cout << "Enter address: ";
        
        std::string address;
        std::cin >> address;

        std::cout << "Enter port: ";
        
        std::string port;
        std::cin >> port;

        size_t separator = port.find("-");

        if (separator != std::string::npos)
        {
            std::string leftBorder = port.substr(0, separator);
            std::string rightBorder = port.substr(separator + 1, port.length() - separator - 1);
            for (int it_port = atoi(leftBorder.c_str()); it_port <= atoi(rightBorder.c_str()); it_port++)
            {

                if (checkConnection(address, std::to_string(it_port)) >= 0)
                {
                    std::cout << "Opened at " << it_port << std::endl;
                }
            }
        }
        else
        {
            if (checkConnection(address, port.c_str()))
            {
                std::cout << "Opened";
            }
            else
            {
                std::cout << "Closed";
            }
        }

    
    }
    
}

