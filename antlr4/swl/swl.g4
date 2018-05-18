grammar swl;

program   : 'begin' statement+ 'end';

statement : assign | add | sub | mult | div | print | ifthenelse | whiledo ;

assign     : 'let' ID 'be' (NUMBER | ID) ;
print      : 'print' (NUMBER | ID) ;
add        : 'add' (NUMBER | ID) 'to' ID ;
sub        : 'sub' (NUMBER | ID) 'to' ID ;
mult       : 'mult' (NUMBER | ID) 'to' ID ;
div        : 'div' (NUMBER | ID) 'to' ID ;
whiledo    : 'while (' boolean ')' wdo statement+ 'end';
wdo        : 'do';
ifthenelse : 'if' boolean ith statement+ 'end'
           | 'if' boolean ith statement+ iels statement+ 'end' ;
ith        : 'then';
iels       : 'else';
boolean    : NOTNOT*(NUMBER | ID) ((CARATTERI|LOGIC) (NUMBER | ID))*
           | '(' boolean ')' ((CARATTERI|LOGIC) '(' boolean ')')*
           | NOTNOT '('boolean')'
           | NOTNOT boolean;

ID        : [a-zA-Z]+ ;
NUMBER    : [0-9]+ ;
CARATTERI : '>=' | '<=' | '>' | '<' | '!=' | '==' ;
LOGIC     : ' and '|' or ';
NOTNOT    : 'not '+;
WS        : [ \r\n\t]+ -> skip;
ErrorChar : . ;
