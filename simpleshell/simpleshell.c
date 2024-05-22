void shell(){
	
    while(1) {
        char buffer[BUFFER_MAX_SIZE];
        uart_send_string("# ");
        read_command(buffer);
        parse_command(buffer);
    }
}

void read_command(char* buffer) {
    int index = 0;
    while(1) {
        buffer[index] = uart_get_char();
        uart_send_char(buffer[index]);
        //meet newline then we know this is the end of the string
        if(buffer[index] == '\n') { 
            buffer[index] = '\0';
            buffer[index+1] = '\n';
            break;
        }
        index++;
    }
}

void parse_command(char* buffer) {
    char* input_string = buffer;
    char* parameter[5]; //5 is the available parameter length
    int para_idx = 0;
    int input_string_len = utils_strlen(input_string);
    for(int i=0; i < input_string_len; i++){
        if(*(input_string+i) == ' '){
            *(input_string+i) = '\0';
            //point to the start of next string
            parameter[para_idx++] = (input_string+i+1);
        }
    }
    
    if(utils_string_compare(input_string,"help")) {
       uart_send_string("help	:print this help menu\n");
       uart_send_string("hello	:print Hello World!\n");
       uart_send_string("info	:Get the hardware's information\n");
    } else if (utils_string_compare(input_string,"hello")) {
       uart_send_string("Hello World!\n");
    }
}