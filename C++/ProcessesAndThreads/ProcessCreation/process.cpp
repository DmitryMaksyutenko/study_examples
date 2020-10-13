#include <iostream>
#include <charconv>
#include <unistd.h>

class MyProcess
{
    private:
        pid_t processId;
        pid_t parentId;

    public:
        MyProcess ()
        {
            // std::cout << "CONSTRUCTOR BEGIN\n";

            int res = fork();
            // std::cout << "CONSTRUCTOR AFTER FORK\n";

            processId = getpid();
            parentId = getppid();

            switch (res){
                case 0:
                    // std::cout << "case 0: child process\n";
                    // std::cout << "Process ID from constructor: " << processId << "\n";
                    // std::cout << "Parent ID from constructor: " << parentId << "\n";
                break;

                default:
                    // std::cout << "default: parent process\n";
                    // std::cout << "Process ID from constructor: " << processId << "\n";
                    // std::cout << "Parent ID from constructor: " << parentId << "\n";
                    // std::cout << "Child ID form constructor: " << res << "\n";
                break;
            }

            // std::cout << "CONSTRUCTOR END\n\n";
        }

        pid_t process() const
        {
            return processId;
        }

        pid_t parent() const
        {
            return parentId;
        }
};

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "./programname number\n";
        return 0;
    }

    std::cout << "MAIN BEFORE CHILD PROCESS CREATION\n";
    std::cout << "MAIN process ID: " << getpid() << "\n";

    int processesCount = std::stoi(argv[1]);

    for (int i = 0; i < processesCount; i++) {
        MyProcess p1;
        std::cout << "MAIN\n";
        std::cout << "Process ID: " << p1.process() << "\n";
        std::cout << "Parent ID: " << p1.parent() << "\n\n";
    }

    return 0;
}
