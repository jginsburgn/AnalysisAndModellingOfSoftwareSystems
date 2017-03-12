//
//  main.cpp
//  003-ObserverPattern
//
//  Created by Jonathan Ginsburg on 3/12/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

//C++ Libraries
#include <iostream>
#include <string.h>

//C Libraries
#include <signal.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define WELCOME_MESSAGE_TTL 10

void parent(int, int);
void child(int, int);
void grandChild(int, int);

int main(int argc, const char * argv[]) {
    system("clear");
    std::cout << "*** DO NOT TYPE ANYTHING ***\n\nWelcome to the multitimer by Jonathan Ginsburg. This project was finished on the morning (5:34am) of Sunday, March the 12th of 2017.\n\tIt employs signals, parallel processes, IPC, and the Observer Pattern. It works as follows: the parent process is created and it forks with an available IPC means, namely a pipe. With the pipe, it communicates to its child the number of seconds that the user wants to set a timer of and the PID of the target process to which the signal should be sent, upon time completion. The child receives this information and forks again, telling its child in turn the PID target and the number of seconds to count. The grandchild counts and sends the signal upon completion, while the parent-child process of registering timers continues. Therefore, the Observer Pattern is used as the parent (the observer) registers for an event, namely time completion, to the subject: its child.\n\n" << std::endl;
    std::string suspenseMessage = "Proceeding in: ";
    for (int i = WELCOME_MESSAGE_TTL; i > 0; --i) {
        printf("%s %2is.", suspenseMessage.c_str(), i);
        fflush(stdout);
        sleep(1);
        for (int j = 0; j < suspenseMessage.length() + 5; ++j) {
            printf("\b");
        }
        fflush(stdout);
    }
    
    //File descriptor holders
    int parent_child[2]; //Communication from parent to child pipes.
    int child_parent[2]; //Communication from child to parent pipes.
    
    //Create pipes
    pipe(parent_child);
    pipe(child_parent);
    
    //Fork
    pid_t forkedPID = fork();
    if (forkedPID == -1) {
        perror("Error forking");
    }
    else if (forkedPID == 0) {
        //Discard unused communication channels
        close(parent_child[1]);
        close(child_parent[0]);
        
        //Execute child and provide communication channels
        child(parent_child[0], child_parent[1]);
    }
    else {
        //Discard unused communication channels
        close(child_parent[1]);
        close(parent_child[0]);
        
        //execute parent and provide communication channels
        parent(child_parent[0], parent_child[1]);
    }
    
    return 0;
}

void signalHandler(int signum, siginfo_t * info, void * context) {
    system("clear");
    puts("*** DO NOT TYPE ANYTHING ***\nTime's up.\a");
    sleep(2);
    return;
}

void parent(int in, int out) {
    //Arrange signal handler details
    struct sigaction act;
    act.sa_sigaction = signalHandler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO | SA_NODEFER;
    
    //Register signal handler
    sigaction(SIGUSR1, &act, NULL);
    
    //Register as many timers as needed
    while (true) {
        system("clear");
        //Query user
        std::cout << "In seconds, set a timer for how long? (or enter exit to end) " << std::flush;
        char buffer[BUFFER_SIZE + 1];
        bzero(buffer, BUFFER_SIZE + 1);
        ssize_t bRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        
        if (bRead == -1) {
            continue;
        }
        buffer[bRead - 1] = 0;
        
        std::string input = buffer;
        if (input == "end") {
            system("clear");
            return;
        }
        
        //Register to child as an observer with number of seconds of timer
        write(out, input.c_str(), input.length());
        
        //Read confirmation and next query (which should be GETPID)
        bzero(buffer, BUFFER_SIZE + 1);
        read(in, buffer, BUFFER_SIZE);
        const std::string GETPID = "GETPID";
        if (GETPID != buffer) {
            puts("Next query was unexpected.");
            puts(buffer);
            return;
        }
        
        //Send target process ID
        bzero(buffer, BUFFER_SIZE + 1);
        sprintf(buffer, " %i", getpid());
        write(out, buffer, strlen(buffer));
    }

}

void child(int in, int out) {
    //Ignore important user 1 signal
    struct sigaction act;
    act.sa_handler = SIG_IGN;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGUSR1, &act, NULL);
    
    //Create buffer
    char buffer[BUFFER_SIZE + 1];
    
    //Empty buffer
    bzero(buffer, BUFFER_SIZE + 1);
    
    //Read
    ssize_t read_count = read(in, buffer, BUFFER_SIZE);
    if (read_count == 0) {
        return;
    }
    
    //Parse information
    int seconds = atoi(buffer);
    
    //Ask for target process' pid
    std::string message = "GETPID";
    write(out, message.c_str(), message.length());
    
    //Read target process' pid
    bzero(buffer, BUFFER_SIZE + 1);
    read(in, buffer, BUFFER_SIZE);
    int targetPID;
    sscanf(buffer, " %i", &targetPID);
    
    //Fork into grandchild to fire signal
    pid_t forkedPID = fork();
    if (forkedPID == -1) {
        perror("Couldn't fork");
        return;
    }
    else if (forkedPID == 0) {
        grandChild(seconds, targetPID);
        return;
    }
    else {
        return child(in, out);
    }
}

void grandChild(int seconds, int pid) {
    //Ignore important user 1 signal
    struct sigaction act;
    act.sa_handler = SIG_IGN;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGUSR1, &act, NULL);
    
    //Count seconds...
    for (int i = 0; i < seconds; ++i) {
        sleep(1);
    }
    
    //Deploy signal
    kill(pid, SIGUSR1);
}
