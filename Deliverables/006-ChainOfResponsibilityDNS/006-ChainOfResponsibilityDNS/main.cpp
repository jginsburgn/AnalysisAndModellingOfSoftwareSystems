//
//  main.cpp
//  006-ChainOfResponsibilityDNS
//
//  Created by Jonathan Ginsburg on 4/18/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

class DNSServer {
public:
    
    typedef enum {
        A,
        NS
    } RecordType;
    
private:
    
    typedef std::pair<RecordType, void *> RecordImage;
    typedef std::pair<std::string, RecordImage> Record;
    typedef std::map<std::string, RecordImage> Records;
    
    Records records;
    
public:
    
    bool resolve(const std::string domain, std::string * response) {
        std::string currentDomain = domain;
        while (true) {
            //Search for records for match
            Records::iterator foundRecord = records.find(currentDomain);
            if (foundRecord != records.end()) {
                RecordImage recordImage = (*foundRecord).second;
                if (recordImage.first == A) {
                    *response = *(std::string *)recordImage.second;
                    return true;
                }
                else if (recordImage.first == NS) {
                    return ((DNSServer *)recordImage.second)->resolve(domain, response);
                }
            }
            
            //Trim domain to higher level for next record search
            std::string::size_type periodPosition = currentDomain.find('.');
            if (periodPosition == std::string::npos) {
                return false;
            }
            currentDomain = currentDomain.substr(periodPosition + 1);
        }
    }
    
    bool addRecord(const RecordType type, const std::string domain, void * recordTarget) {
        RecordImage recordImage = {type, recordTarget};
        Record record = {domain, recordImage};
        return records.insert(record).second;
    }
};

int main(int argc, const char * argv[]) {
    DNSServer root;
    DNSServer comTLD;
    root.addRecord(DNSServer::RecordType::NS, "com", &comTLD);
    std::string target("1.1.1.1");
    comTLD.addRecord(DNSServer::RecordType::A, "ariel.com", &target);
    std::string response;
    if (root.resolve("ariel.com", &response)) {
        std::cout << "Resolution: " << response << std::endl;
    }
    else {
        std::cout << "No resolution found." << std::endl;
    }
    
    return 0;
}
