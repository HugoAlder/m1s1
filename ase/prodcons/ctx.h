typedef void (func_t) (void *);

#define MAGIC 0xCAFEBABE
#define TIMER_ALARM 0xF8
#define TIMER_PARAM 0xF4
#define TIMER_IRQ 2

enum state_e {
  CTX_RDY,
  CTX_RUNNING,
  CTX_TERMINATED
};

struct ctx_s * head_ctx;
struct ctx_s * current_ctx;

struct ctx_s {
  void * ebp;
  void * esp;
  int magic;
  char * stack;
  func_t * entrypoint;
  char * arg;
  enum state_e state;
  struct ctx_s * next;
  struct ctx_s * prev;
};

int create_ctx(int stack_size, func_t f, void * args);
int init_ctx(struct ctx_s * ctx, int stack_size, func_t f, void * args);
void start_current_ctx();
void switch_to_ctx(struct ctx_s * ctx);
void yield();
void irq_disable();
void irq_enable();
