grammar swl;

program     :   'begin' statement+ 'end';

statement   :   assign | add | sub | mult | div | ask | print | ifthenelse | whiledo;

assign      :   'let' ID 'be' (NUMBER | ID) ;
print       :   'print' (NUMBER | ID) ;
ask         :   'ask' ID ;
add         :   'add' (NUMBER | ID) 'to' ID ;
sub         :   'sub' (NUMBER | ID) 'to' ID ;
mult        :   'mult' (NUMBER | ID) 'to' ID ;
div         :   'div' (NUMBER | ID) 'to' ID ;

whiledo     :   'while' boolean wdo statement+ 'end';
wdo         :   'do';

ifthenelse  :   'if' boolean ithen statement+ 'end'
			|   'if' boolean ithen statement+ ielse statement+ 'end'
            ;            
ithen       :   'then';
ielse       :   'else';

boolean     :   var ((opconf|logic) var)*
            |   boolean ((opconf|logic) boolean)+
            |   lnot* lb boolean rb
            ;

var         :   (NUMBER|ID) | lnot+ var ;

logic       :   'and' | 'or';
lnot        :   'not';

lb          :   '(';
rb          :   ')';

opconf      :   '>=' | '<=' | '>' | '<' | '!=' | '==' ;

ID         :    [a-zA-Z]+ ;
NUMBER     :    [0-9]+ ;
WS         :    [ \r\n\t]+ -> skip;
ErrorChar  :    . ;
