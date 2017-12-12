extern void user_process();

int main(int argc, char **argv) {

    /* hardware initialisation and cie */
    /* .. your code here ... */
    
    /* user mode */
    user_process();
    return 0;
}

