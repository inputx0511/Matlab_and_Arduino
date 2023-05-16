clc;
clear ALL;
close all;
delete(instrfind({'Port'},{'COM5'}));
s = serial('COM5', 'BaudRate', 9600);
prompt = 'What is the original value? ';
val = input(prompt, 's')
fopen(s);
while true
    %val = input(prompt, 's')
    %ischar(val)
    fprintf(s, val)
    val_recive = fscanf(s)
    %fclose(s);
end
