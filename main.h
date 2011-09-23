
#define MAXEVENTS	40960
#define MAX_PORCESS	20480
#define BUF_SIZE	4096

#define MAX_URL_LENGTH	128

#define PORT 8080

#define INDEX_FILE "/index.htm"

#define USE_SENDFILE 1

struct process {
    int sock;
    int status;
    int response_code;
    int fd;
    int read_pos;
    int write_pos;
    int total_length;
    char buf[BUF_SIZE];
};

void send_response_header(struct process *process);

int setNonblocking(int fd);

struct process* find_process_by_sock(int sock);

struct process* accept_sock(int listen_sock);

void read_request(struct process* process);

void send_response_header(struct process *process);

void send_response(struct process *process);

void cleanup(struct process *process);

void handle_error(struct process *process, char* error_string);

void reset_process(struct process *process);

int open_file(char *filename);

