/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104

********************************Assignment No. 1**************************
 AIM:-Shell programming Write a program to implement an address book with options given below:
 a) Create address book. b) View address book. c) Insert a record. d) Delete a record.
 e) Modify a record. f) Exit.
*/
 
#! user/bin/bash

it=0
a=1
while [[ $op -lt 7 ]]
do
        echo enter the option
        echo "1 for create"
        echo "2 for add"
        echo "3 for display"
        echo "4 for search"
        echo "5 for delete"
        echo "6 for modify"
        echo "7 for exit"
        echo "enter u r choice"
        read op
word="$op"
case "$word" in

"1")
        if [ "$op" == "1" ]
                then
                echo "Enter the name for the database"
                read db
                touch "$db"
        fi
;;
"2")
        if [ "$op" == "2" ]
                then
                echo "in which database u want to add records"
                read db
                echo "enter the no. of records"
                read n
        while [ $it -lt $n ]
        do
                echo "enter id:"
                read id1
                echo "enter name:"
                read nm
                pa1="^[A-Za-z]"
        while [[ ! $add =~ $pa ]] 
        do
                echo "enter valid address:"
                read add
        done
        echo "enter address:"
        read add
        pa="^[A-Za-z0-9]"
        while [[ ! $add =~ $pa ]] 
        do
                echo "enter valid address:"
                read add
        done
        #echo $add

        echo "enter phone no.:"
        read ph
        pat="^[0-9]{10}$"
        while [[ ! $ph =~ $pat ]]
        do
                echo "please enter phone number as XXXXXXXXXX:"
                read ph
        done
        #echo $ph

        echo "eter email:"
        read em
        patem="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
        while [[ ! $em =~ $patem ]]
        do
                echo "please enter valid email address"
                read em
        done
        #echo $em

        echo "$id1,$nm,$add,$ph,$em" >> "$db"

        it=`expr $it + 1`
        echo "$it record entered"
        done
        fi
;;
"3")
        if [ "$op" == "3" ]
                then
                echo "enter name of database from where data to be display:"
                read db
                cat $db
        fi
;;
"4")
        if [ "$op" == "4" ]
                then
                echo "enter name of database from where to search:"
                read db
                echo "enter email to be search:"
                read em1
                grep $em1 $db
                echo "record found"
                else
                echo "not found"
        fi
;;

"5")
        if [ "$op" == "5" ]
                then
                echo "enter name of database:"
                read db
                echo "enter id:"
                read id1
                echo "enter line no. u want to delete:"
                read linenumber

                for line in `grep -n "$id1" $db`
                do
                number=`echo "$line" | cut -c1`
                #echo $number
                if [ $number == $linenumber ]
                then
                lineRemove="${linenumber}d"
                sed -i -e "$lineRemove" $db
                echo "record removed"
                fi
                #echo
                cat $db
                done
        fi
;;

"6")
        if [ "$op" == "6" ]
                then
                echo "enter name of database:"
                read db
                echo "enter id:"
                read id1
                echo "enter line u want to modify:"
                read linenumber

                for line in `grep -n "$id1" "$db"`
                do
                number=`echo "$line" | cut -c1`

                if [ "$number" == "$linenumber" ]
                then
                echo "what would u like to change"
                echo "\"id,name,address,mobile,email\""
                read edit
                linechange="${linenumber}s"
                sed -i -e "$linechange/.*/$edit/" $db
                echo record edited    
                fi
                done
        fi
;;
"7")
        echo "bye"
;;
*) echo invalid input

esac
done

******************************OUTPUT****************************************

/*
ssl@ssl-ThinkCentre-M60e:~$ chmod +x address_book.sh
ssl@ssl-ThinkCentre-M60e:~$ ./address_book.sh
enter the option
1 for create
2 for add
3 for display
4 for search
5 for delete
6 for modify
7 for exit
enter u r choice
1
Enter the name for the database
pr
enter the option
1 for create
2 for add
3 for display
4 for search
5 for delete
6 for modify
7 for exit
enter u r choice
2
in which database u want to add records
pr
enter the no. of records
1
enter id:
1
enter name:
priyanka
enter address:
pune
enter phone no.:
9876543210
eter email:
priya_09@gmail.com
1 record entered
enter the option
1 for create
2 for add
3 for display
4 for search
5 for delete
6 for modify
7 for exit
enter u r choice
3
enter name of database from where data to be display:
pr
1,priyanka,pune,9876543210,priya_09@gmail.com
enter the option
1 for create
2 for add
3 for display
4 for search
5 for delete
6 for modify
7 for exit
enter u r choice
4
enter name of database from where to search:
pr
enter email to be search:
pri_09@gmail.com
record found
enter the option
1 for create
2 for add
3 for display
4 for search
5 for delete
6 for modify
7 for exit
enter u r choice
6
enter name of database:
pr
enter id:
2
enter line u want to modify:
1
what would u like to change
"id,name,address,mobile,email"
23 priya mumbai 9785634120 priya_90@gmail.com
record edited
enter the option
1 for create
2 for add
3 for display
4 for search
5 for delete
6 for modify
7 for exit
enter u r choice
5
enter name of database:
pr
enter id:
23
enter line no. u want to delete:
1
record removed
enter the option
1 for create
2 for add
3 for display
4 for search
5 for delete
6 for modify
7 for exit
enter u r choice
7
bye
ssl@ssl-ThinkCentre-M60e:~$ 

*/
