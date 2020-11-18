typedef struct LlstQnode {
    int value;
    struct LlstQnode* next;
    struct LlstQnode* prev;
}LlstQnode;