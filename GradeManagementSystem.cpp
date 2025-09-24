#include <iostream>


void enterGrades(float grades[], int& students){
    std::cout<<"\n";
    std::cout<<"how many grades to enter(Max is 100)?: ";
    std::cin >> students;

        for(int i = 0; i < students; i++){

        std::cout<<"Enter grade #"<<i + 1<<": ";
        std::cin>> grades[i] ; // the "i" in grades[i] is the position of the number in the array where your input is being put in like grade{90, 100}
          
        }
}



void displayGrades(const float grades[], int students){
    std::cout<<"\n";
    std::cout<<"displaying grades"<<std::endl;

        for(int i = 0; i < students; i++){

        std::cout<<"grades #"<< i + 1 <<": "<<grades[i]<<std::endl; // the "i" in grades[i] is the position of the number in the array of when you last inputed you numbers(hince your grades that you input)

        }
}



float calculateAverage(const float grades[], int students){
    float total;

    for (int i = 0; i <= students; i++){
      
        total += grades[i]; // this part i had trouble to figure out how to add continuasly i was looking at math problems and came around to += which worked 
            
    } 

    std::cout<<"\n";
    total = total/students ; 
    std::cout<<"the total Average calculated is: " <<total<<std::endl;
    return total; // had an error about a return type since i was not returning it in the beginnning so i just added the return and the total  

}


float findMax(const float grades[], int students){
    float maxGrades = grades[0]; 
    float lowestGrade = grades[0];
    


    for (int i = 0; i < students; i++ ){ 
        if(maxGrades < grades[i]){ 
                 
        maxGrades = grades[i];
        }  
    }

    for(int i = 0; i < students; i++){
        if(lowestGrade > grades[i]){
        lowestGrade = grades[i];
        }
    }

 std::cout<<"\n";
 std::cout<<"the max Grades is: "<< maxGrades<< std::endl;
 std::cout<<"the Lowest Grade is: "<< lowestGrade<<std::endl; 
    return maxGrades;
}


int countInRange(const float grades[], int students, float min, float max){

    float range1, range2;
    int findNum = 0;

    std::cout<<"\n";
    std::cout<<"Enter the two numbers for the range let the first number be the lowest and the second highest: ";
    std::cin>> range1 >> range2;

    std::cout<<"Numbers between "<< range1 <<"-"<< range2 <<std::endl;

     for (int i = 0; i < students; i++ ){
        if(range1 <= grades[i] && range2 >= grades[i]){  
         
        /*
        range1 = grades[i];       
        range2 = grades[i]; 
        both these codes in my head I thought it will work but in trail and error i think its best to take this out i was just overthinking the code. 

         lets say grade is 100, 90, 70, 40  now the user put the range 50 95 
         if statment works becuase it goes from the top at 95 exluding 100 beaceuse we are trying to find numbers less than 95 now the range1(50) <= 90 true and range2(95) >= 90 true then it keeps going down
         until rang1(50)<= 40 false which stops the code and from there we will have our total numbers that were between 50 95 beacuase of the findNum++, which adds up each loop = 2 until it the if statement is false.          
        */

        findNum++;    
        }  
    }

    std::cout<< "Total grades in range: "<< findNum << std::endl;
    return findNum;

}
    

int searchGrade(const float grades[], int students, float target){
int amount;



    std::cout<< "\n";
    std::cout<<"Enter a Specific grade: ";
    std::cin >> target;

     for(int i = 0; i < students; i++){
        if(target == grades[i]){
            target = grades [i];
            amount++;
            std::cout<<"Specific grades found there is: "<<amount<<std::endl;  
        }      
     }  


     if(amount == 0 ){
    std::cout<<"Grade not found"<<std::endl;
     }

    return target; 


}






int main () {

float total;
int num; 
int students= 0;
float grades[100];
float min = 0;
float max = 0;
float target;


std::cout<<"============================================"<<std::endl;

std::cout<<" Grade Management System"<< std::endl;

std::cout<<"============================================"<<std::endl;
std::cout<<"1. Enter Grades\n" <<"2. Display all grades\n"<<"3. Calculate average grade\n"<< "4. Find highest and lowest grades\n"<< "5. Count grades in a specific range\n"<<"6. Search for a specefic grade\n"<<"7. Exit"<<std::endl;\


do {// do while loops helps contain the values of what the user input into "students" and "grades" without getting reset since the value are declared outside the do-while loop. 
std::cout<<"\n";
std::cout<<"Enter your choice: ";
std::cin >> num; 

switch(num)// switch cases goes through what ever number the uesr inputs.
{
case 0:
case 1:
    enterGrades(grades, students);
    break;

case 2:
    if (students>0){
        displayGrades(grades, students);
        break;
    }
    else{
        std::cout<<"you did not input any grades"<<std::endl;
        break;
    }

case 3: 
    if (students > 0 ){
        calculateAverage(grades, students);
        break;
    }else{
        std::cout<<"you did not input any grades to calculate average"<<std::endl;
        break;
    }

case 4:
    if(students > 0 ){
        findMax(grades, students);
        break;
    }else{
        std::cout<<"you did not input any grades"<<std::endl;
        break;
    }

case 5:
    if (students > 0 ){
        countInRange(grades, students, max, min);
        break;
    }else{
        std::cout<< "You did not put any grades"<<std::endl;
        break;
    }
case 6:
    if (students > 0){
        searchGrade(grades, students, target);
        break;
    }else{

        std::cout<<" you did not put any grades"<<std::endl;
    }


}

} while (num != 7);
{
    std::cout<<"You have exited the Graded Management System"<<std::endl; 
}

    return 0;

}
