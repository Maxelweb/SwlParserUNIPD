grammar swl;

program   : 'begin' statement+ 'end';

statement : assign | add | print | condition ;

assign    : 'let' ID 'be' (NUMBER | ID) ;
print     : 'print' (NUMBER | ID) ;
add       : 'add' (NUMBER | ID) 'to' ID ;
condition : 'if' (NUMBER|ID) CONF (NUMBER|ID) 'then' statement;

ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
CONF      : [><!=];
WS        : [ \n\t]+ -> skip;
ErrorChar : . ;
