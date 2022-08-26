#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <sstream>
using namespace std;

string principal_password;
void gotoxy(int x, int y);
void school_header();
void anyword();
string mainmenu();
string admin_header();
void admin_whole_function();
string admin_manage_staff();
string admin_manage_students();
string admin_manage_subject();
void teacher_header();
string teacher_meanu();
void fixstudentcount(); // use kerna ha isko abhi
string manage_student();
void Student_header();
string student_menu();
void clear_screen();
// ************ start of prototypes************
void Add_student(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[]);
void AddStudentIntoArr(string s_name, string f_name, string password_for_studentt, float roll_no, int fee, float marks, int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[]);
void Add_teacher(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
void AddTeacheIntoArr(string tname, string t_fname, string tpassword, string phone_no, string addres, string cnicc, string account_noo, float salari, int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
int max_salary_t(int s, int e, float salary[]);
int mini_salary_t(int s, int e, float salary[]);
int max_marks(int s, int e, float stu_marks[]);
int mini_marks(int s, int e, float stu_marks[]);
int max_sub_marks(int s, int e, float test_marks[]);
void class_performance_marks(int s, int e, float test_marks[]);
void show_max_mark_in_sub(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[]);                            // mark cout use kr raha hon me
void show_max_mark_in_class_performance(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[]); // mark cout use kr raha hon me
void sort_wrt_max_marks(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int stu_fee[], float stu_marks[]);
void sort_wrt_mini_marks(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int stu_fee[], float stu_marks[]);
void sort_wrt_max_salary(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
void sort_wrt_mini_salary(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
void update_salary(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
bool deduct_salary(int teacher_count, string teacher_name[], float salary[]);
bool remove_teacher(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
bool remove_student(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[]);
bool remove_subject(int subject_count, string teacher_nameforsubject[], string subject[], string duration[]);
void Addsubject(int subject_count, string teacher_nameforsubject[], string subject[], string duration[]);
void addsubjectintoarr(string te_name, string sub_name, string dura, int subject_count, string teacher_nameforsubject[], string subject[], string duration[]);
void attendence_of_student(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int student_check[]);
void viewlecture(int subject_count, string teacher_nameforsubject[], string subject[], string duration[]);
void view_present_students(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int student_check[]);
void view_absent_students(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int student_check[]);
void Add_marks_ofstudent(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[]);
void Add_class_performance_marks(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[]);
void calculate_aggregate(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[], float test_marks[], float aggrigate[]);
int check_max_aggrigate(int s, int e, float aggrigate[]);
void merit_list(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[], float class_performance_marks[], float aggrigate[]);
void view_teacer_his_own_profie(string tname, string password, int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
// string _return_role(string stu_name[], )
void see_class_performance_speciic(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[]);
void view_student_own_profile(string s_namee, string s_password, int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], string password_for_student[]);
void see_statistics_of_test_marks(int stu_count, float test_marks[]);
// void see_statistics_of_class_performance_marks(int stu_count, float class_performance_marks[]);
void statsistics_of_class_performance(int stu_count, float class_performance_marks[]);


void see_his_own_result(string s_namee, string s_password, int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], float test_marks[], float class_performance_marks[], float aggrigate[]);

//**********file handling**************

void add_student_intofile(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[]);
void add_teacher_intofile(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[]);
void add_subject_intofile(int subject_count, string teacher_nameforsubject[], string subject[], string duration[]);
void Add_class_performance_marksintofile(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[]);
void add_test_marks_intoFile(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[]);

void Add_stu_msg_to_teacher_intofile(int stu_count, string feedback_from_student[]); // for teacher to see that rply
void add_teacher_rpl__to_admin_intofile(int teacher_count, string messge_from_teacher[]);
void teacher_aanouncement(int teacher_count, string msg);

// void
//********** reading *****from file
string parseData(string record, int field);
int load_stu_data(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[]);
main()
{

     // declare array in main fucing name

     int max_imit_for_student = 100;

 
     // int stu_count=0;teacher_count=3,subject_count=3;
     int stu_count =0, teacher_count = 3, subject_count = 3, mark_count = 3;
     float stu_roll_num[100];// = {123, 234, 345};
     int stu_fee[100];// = {4500, 5000, 3600};
     float stu_marks[100];//  = {700, 800, 900};
     float salary[15] = {50000, 60000, 30000};
     string stu_name[100]   ;//          = {"hasan nawaz", "emma stone", "mia ahsan"};
     string stu_f_name[100]    ;//       = {"muhamad nawaz", "jean rock", "mia roman"};
     string password_for_student[100] ;// = {"s001", "4k", "black"};
     string teacher_name[15] = {"Ahmed nadeem", "ok", "dean ambros"};
     string teacher_father_name[15] = {"nadeem kasmi", "danial", "seth rollin"};
     string password_for_teacher[15] = {"hasan001", "ok", "hasan003"};
     string phone_number[15] = {"03236644837", "03246645847", "03247460600"};
     string address[15] = {"k block hall", "edhi hall ha", "khalid hall room 53"};
     string cnic[15] = {"3310014841911", "3310065933933", "3310065987645"};
     string account_no[15] = {"54004", "98764", "09745"};
     int student_check[100] = {1, 0, 1}; // attendence
     string subject[8] = {"Physics", "Mathmatics", "Biology"};
     string duration[8] = {" 1 : 30 ", " 2 : 00 ", " 1 : 45"};
     string teacher_nameforsubject[8] = {"Haider", "Elsa", "Rayan"};
     float class_performance_marks[100] = {30, 45, 67};
     float test_marks[100] = {450, 564, 987};
     float aggrigate[100] = {12, 83, 3};

     string admin_msg;
     string messge_from_teacher[10] = {"hello sir g kasy han ap?", "si salary berha dein", "sir g mar z ha"};
     string message_from_t_to_stu[10];
     string feedback_from_student[100] = {"hello", "hi", "bye"};

     string role;
     string studential_name;
     string studential_password;
     string password2;
     string teacher_password;
     string student_password;
     string msg_to_class;

     // save in file//
     // add_student_intofile(stu_count, stu_name, stu_f_name, password_for_student, stu_roll_num, stu_fee, stu_marks);
     // add_teacher_intofile(teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);
     // add_subject_intofile(subject_count, subject, teacher_nameforsubject, duration);
     // add_test_marks_intoFile(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks);
     // Add_class_performance_marksintofile(stu_count, stu_name, stu_f_name, stu_roll_num, class_performance_marks);
     // teacher_aanouncement(teacher_count, msg_to_class);
     // add_teacher_rpl__to_admin_intofile(teacher_count, messge_from_teacher);
     // Add_stu_msg_to_teacher_intofile(stu_count, feedback_from_student);
     // //******* read to file***********
     stu_count = load_stu_data(stu_count, stu_name, stu_f_name, password_for_student, stu_roll_num, stu_fee, stu_marks);
     
     // Checking whether the data is loaded successfully or not
     for(int x = 0; x < stu_count; x++)
     {
          cout << stu_name[x];
          getch();
     }
     /////////
     clear_screen();
     school_header();
     string main_option; // changeing
     string teach_name;
     string password1 = "ok";
     do
     {
          main_option = mainmenu(); // sign in a admin reacer and soo o
          if (main_option == "1")
          {
               system("cls");
               school_header();
               gotoxy(20, 10);
               cout << "Enter your  admin name" << endl;

               gotoxy(20, 11);
               cin.ignore();
               getline(cin, role);
               if (role == "ok")
               {
                    gotoxy(60, 10);
                    cout << "Enter your password" << endl;
                    // cin.ignore();
                    gotoxy(60, 11);
                    cin >> principal_password;
                    if (principal_password.length() <= 8 && principal_password == password1)
                    {

                         bool flag = false;
                         string option = " ";

                         while (option != "7")
                         {

                              clear_screen();
                              option = admin_header();
                              if (option == "1")
                              {
                                   string optio = admin_manage_staff();
                                   if (optio == "1")
                                   {

                                        clear_screen();
                                        school_header();
                                        Add_teacher(teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);
                                        teacher_count++;
                                        anyword();
                                   }
                                   else if (optio == "2")
                                   {

                                        clear_screen();
                                        school_header();
                                        if (remove_teacher(teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary) == true)
                                        {
                                             cout << " teacher has been removed";
                                             teacher_count--;
                                        }
                                        anyword();
                                   }
                                   else if (optio == "3")
                                   {

                                        clear_screen(); //
                                        school_header();
                                        sort_wrt_mini_salary(teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);

                                        anyword();
                                   }
                                   else if (optio == "4")
                                   {

                                        clear_screen();
                                        school_header();
                                        update_salary(teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);

                                        anyword();
                                   }
                                   else if (optio == "5")
                                   {
                                        string opti;
                                        cout << " press 1 to view salaary in asending order" << endl;
                                        cout << "press 2 to view salary in desending order" << endl;
                                        cin >> opti;
                                        if (opti == "1")
                                        {
                                             clear_screen();
                                             school_header();
                                             sort_wrt_mini_salary(teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);
                                             anyword();
                                        }
                                        else if (opti == "2")
                                        {
                                             clear_screen();
                                             school_header();
                                             sort_wrt_max_salary(teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);
                                             anyword();
                                        }
                                   }
                                   else if (optio == "6")
                                   {

                                        anyword();
                                   }
                              }
                              else if (option == "2")
                              {
                                   string opt = "";
                                   opt = admin_manage_students();
                                   if (opt == "1")
                                   {
                                        system("cls");
                                        school_header();
                                        Add_student(stu_count, stu_name, stu_f_name, password_for_student, stu_roll_num, stu_fee, stu_marks);
                                        stu_count++;
                                        anyword();
                                   }
                                   else if (opt == "2")
                                   {

                                        clear_screen();
                                        school_header();
                                        if (remove_student(stu_count, stu_name, stu_f_name, password_for_student, stu_roll_num, stu_fee, stu_marks) == true)
                                        {
                                             cout << "student has been removed";
                                             stu_count--;
                                        }

                                        anyword();
                                   }
                                   else if (opt == "3")
                                   {
                                        string option;
                                        do
                                        {
                                             cout << "press 1 to see student according to greater marks" << endl;
                                             cout << "press 2 to see student according to lesser marks" << endl;
                                             cin >> option;
                                             if (option == "1")
                                             {
                                                  clear_screen();
                                                  school_header();
                                                
                                                  // load_stu_data(stu_count,stu_name, stu_f_name, password_for_student, stu_roll_num, stu_fee, stu_marks);
                                                  // stu_count++;
                                                  
                                                  sort_wrt_max_marks(stu_count, stu_name, stu_f_name, stu_roll_num, stu_fee, stu_marks);

                                                  anyword();
                                             }
                                             else if (option == "2")
                                             {
                                                  clear_screen();
                                                  school_header();
                                                  sort_wrt_mini_marks(stu_count, stu_name, stu_f_name, stu_roll_num, stu_fee, stu_marks);

                                                  anyword();
                                             }
                                        } while (option != "1" && option != "2");
                                   }
                                   else if (opt == "4")
                                   {

                                        anyword();
                                   }
                              }
                              else if (option == "3") // masla
                              {
                                   string optionn = admin_manage_subject();
                                   if (optionn == "1")
                                   {
                                        clear_screen();
                                        school_header();
                                        Addsubject(subject_count, subject, teacher_nameforsubject, duration);
                                        subject_count++;
                                        anyword;
                                   }
                                   else if (optionn == "2")
                                   {
                                        clear_screen();
                                        school_header();

                                        viewlecture(subject_count, teacher_nameforsubject, subject, duration);
                                        anyword();
                                   }
                                   else if (optionn == "3")
                                   {

                                        clear_screen();
                                        school_header();
                                        if (remove_subject(subject_count, teacher_nameforsubject, subject, duration) == true)
                                        {
                                             cout << "sunject has been removed" << endl;
                                        }
                                        subject_count--;
                                        anyword();
                                   }
                                   else if (optionn == "4")
                                   {
                                        getch();
                                   }
                              }
                              else if (option == "4")
                              {
                                   clear_screen();
                                   school_header();

                                   cout << " Enter the announcement u wnat to sent to teacherz" << endl;
                                   // getline(cin, msgg);
                                   cin.ignore();
                                   getline(cin, admin_msg);
                                   anyword();
                              }
                              else if (option == "5")
                              {
                                   clear_screen();
                                   school_header();

                                   if (deduct_salary(teacher_count, teacher_name, salary) == true)
                                   {
                                        cout << "salry has been deducted" << endl;
                                   }
                              }
                              else if (option == "6") // isue a raha ha bosss
                              {
                                   clear_screen();
                                   do
                                   {
                                        clear_screen();
                                        school_header();

                                        gotoxy(20, 10);
                                        cout << "Enter new password" << endl;

                                        gotoxy(20, 11);
                                        cin.ignore();
                                        getline(cin, password1);

                                        if (password1.length() <= 8)
                                        {
                                             gotoxy(60, 10);
                                             cout << "Confirm New password" << endl;
                                             gotoxy(60, 11);
                                             cin >> principal_password;

                                             if (principal_password == password1)
                                             {

                                                  anyword();
                                             }
                                             else
                                             {
                                                  cout << "warning >> rong input" << endl;
                                             }
                                        }
                                   } while (password1 != principal_password);
                              }
                              else if (option == "6.5")
                              {
                                   clear_screen();
                                   school_header();
                                   for (int i = 0; i < teacher_count; i++)
                                   {
                                        cout << teacher_name[i] << " : " << endl;
                                        cout << messge_from_teacher[i] << endl; // kerna ha iskon
                                   }
                                   anyword();
                              }
                              else if (option == "7")
                              {
                                   cout << " we are logging out" << endl;
                                   anyword();
                              }
                              else
                              {
                                   anyword();
                              }
                         }
                    }
               }
          }
          else if (main_option == "2") // for teacher///
          {

               clear_screen();
               school_header();
               gotoxy(5, 10);
               cout << "Enter your teacher name";
               cin.ignore();
               gotoxy(5, 11);
               getline(cin, teach_name);
               gotoxy(40, 10);
               cout << "enter password";
               //      cin.ignore();
               gotoxy(40, 11);
               getline(cin, teacher_password);

               // do
               // {

               // clear_screen();
               // school_header();
               for (int i = 0; i < teacher_count; i++) // teacher_count ana ha condition me
               {
                    if (teach_name == teacher_name[i] && teacher_password == password_for_teacher[i])
                    {
                         clear_screen();
                         string store_var_for_teac_menu = "1";
                         // school_header();
                         while (store_var_for_teac_menu != "10")
                         {
                              store_var_for_teac_menu = teacher_meanu();
                              if (store_var_for_teac_menu == "1")
                              {
                                   clear_screen();
                                   school_header();
                                   attendence_of_student(stu_count, stu_name, stu_f_name, stu_roll_num, student_check);
                                   // stu_count++;
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "0.1")
                              {
                                   clear_screen();
                                   school_header();
                                   view_teacer_his_own_profie(teach_name, teacher_password, teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "2")
                              {
                                   clear_screen();
                                   school_header();
                                   view_present_students(stu_count, stu_name, stu_f_name, stu_roll_num, student_check);
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "3")
                              {
                                   clear_screen();
                                   school_header();
                                   view_absent_students(stu_count, stu_name, stu_f_name, stu_roll_num, student_check);
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "4")
                              {
                                   clear_screen();
                                   school_header();
                                   Add_marks_ofstudent(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks); //, float subject_2_marks[], float subject_3_marks[], float subject_4_marks[], float subject_5_marks[])

                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "4.5")
                              {
                                   clear_screen();
                                   school_header();
                                   show_max_mark_in_sub(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks);

                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "5")
                              {
                                   clear_screen();
                                   school_header();
                                   Add_class_performance_marks(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks);

                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "5.5")
                              {
                                   clear_screen();
                                   school_header();
                                   show_max_mark_in_class_performance(stu_count, stu_name, stu_f_name, stu_roll_num, class_performance_marks);

                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "5.6")
                              {
                                   clear_screen();
                                   school_header();
                                   calculate_aggregate(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks, class_performance_marks, aggrigate);
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "6")
                              {
                                   clear_screen();
                                   school_header();
                                   // merit list type generate hoi ha ye broo
                                   merit_list(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks, class_performance_marks, aggrigate);
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "7")
                              {
                                   clear_screen();
                                   school_header();
                                   // calculate_aggregate(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks, class_performance_marks, aggrigate);
                                   see_class_performance_speciic(stu_count, stu_name, stu_f_name, stu_roll_num, class_performance_marks);
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "8")
                              {
                                   clear_screen();
                                   school_header();
                                   // see msg from admin
                                   cout << admin_msg << endl;
                                   anyword();
                                   // store v kerty heinabhi yara sab ko lemme do
                              }
                              else if (store_var_for_teac_menu == "8.8")
                              {
                                   clear_screen();
                                   school_header();
                                   cout << " write something to class" << endl;
                                   cin.ignore();
                                   getline(cin, msg_to_class);
                              }
                              else if (store_var_for_teac_menu == "9")
                              {
                                   clear_screen();
                                   school_header();
                                   for (int i = 0; i < stu_count; i++)
                                   {
                                        cout << stu_name[i] << " : ";
                                        cout << feedback_from_student[i] << endl; // kerna ha iskon
                                   }
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "9.5") // smjh ni a rahi
                              {
                                   clear_screen();
                                   school_header();
                                   for (int i = 0; i < teacher_count; i++)
                                   {
                                        if (teach_name == teacher_name[i] && teacher_password == password_for_teacher[i])
                                        {
                                             cout << " write something to admin" << endl;
                                             cin.ignore();
                                             getline(cin, messge_from_teacher[i]);
                                        }
                                   }

                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "9.10")
                              {
                                   clear_screen();
                                   school_header();
                                   statsistics_of_class_performance(stu_count, class_performance_marks);
                                   anyword();
                              }

                              else if (store_var_for_teac_menu == "9.9")
                              {
                                   clear_screen();
                                   school_header();
                                   see_statistics_of_test_marks(stu_count, test_marks);
                                   anyword();
                              }
                              else if (store_var_for_teac_menu == "10")
                              {
                                   anyword();
                              }
                         }
                    } // while (store_var_for_teac_menu != "1" && store_var_for_teac_menu != "2" && store_var_for_teac_menu != "3" && store_var_for_teac_menu != "4" && store_var_for_teac_menu != "5" && store_var_for_teac_menu != "6" && store_var_for_teac_menu != "7" && store_var_for_teac_menu != "8" && store_var_for_teac_menu != "9" && store_var_for_teac_menu != "10");
               }
          }
          else if (main_option == "3") // for student
          {

               clear_screen();
               school_header();
               gotoxy(5, 10);
               cout << "Enter your  name";
               cin.ignore();
               gotoxy(5, 11);
               getline(cin, studential_name);
               gotoxy(40, 10);
               cout << "Enter password";
               //      cin.ignore();
               gotoxy(40, 11);
               getline(cin, studential_password);

               for (int i = 0; i < stu_count; i++) // teacher_count ana ha condition me
               {
                    if (studential_name == stu_name[i] && studential_password == password_for_student[i])
                    {
                         clear_screen();
                         string store_var_for_student_menu = "1";
                         // school_header();
                         while (store_var_for_student_menu != "6")
                         {
                              store_var_for_student_menu = student_menu();
                              if (store_var_for_student_menu == "1")
                              {
                                   clear_screen();
                                   school_header();
                                   view_student_own_profile(studential_name, studential_password, stu_count, stu_name, stu_f_name, stu_roll_num, password_for_student);
                                   anyword();
                              }
                              else if (store_var_for_student_menu == "2")
                              {
                                   clear_screen();
                                   school_header();
                                   // view_fee_chalan();kerna ha
                                   anyword();
                              }
                              else if (store_var_for_student_menu == "3")
                              {
                                   clear_screen();
                                   school_header();
                                   // view_present_students(stu_count, stu_name, stu_f_name, stu_roll_num, student_check);
                                   see_his_own_result(studential_name, studential_password, stu_count, stu_name, stu_f_name, password_for_student, stu_roll_num, test_marks, class_performance_marks, aggrigate);
                                   anyword();
                              }
                              else if (store_var_for_student_menu == "3.3")
                              {
                                   clear_screen();
                                   school_header();
                                   merit_list(stu_count, stu_name, stu_f_name, stu_roll_num, test_marks, class_performance_marks, aggrigate);

                                   anyword();
                              }
                              else if (store_var_for_student_menu == "4.5")
                              {
                                   clear_screen();
                                   school_header();
                                   cout << msg_to_class << endl;
                                   anyword();
                                   // here we have to store all kind of thingz
                              }
                              else if (store_var_for_student_menu == "4")
                              {
                                   clear_screen();
                                   school_header();
                                   // kerna ha abhi
                                   anyword();
                              }

                              else if (store_var_for_student_menu == "5") // smjh ni a rahi
                              {
                                   clear_screen();
                                   school_header();

                                   for (int i = 0; i < stu_count; i++)
                                   {
                                        if (studential_name == stu_name[i] && studential_password == password_for_student[i])
                                        {
                                             cout << " write something to teacher" << endl;
                                             cin.ignore();
                                             getline(cin, feedback_from_student[i]);
                                        }
                                   }

                                   anyword();
                              }

                              else if (store_var_for_student_menu == "6")
                              {
                                   anyword();
                              }
                         }
                    } // while (store_var_for_teac_menu != "1" && store_var_for_teac_menu != "2" && store_var_for_teac_menu != "3" && store_var_for_teac_menu != "4" && store_var_for_teac_menu != "5" && store_var_for_teac_menu != "6" && store_var_for_teac_menu != "7" && store_var_for_teac_menu != "8" && store_var_for_teac_menu != "9" && store_var_for_teac_menu != "10");
               }
          }
          else if (main_option == "4")
          {
               clear_screen();
               cout << "we are logging out" << endl;
               break;
          }
     } while (main_option == "1" || main_option == "2" || main_option == "3" || main_option == "4");
}

string mainmenu()
{
     string option;
     do
     {
          clear_screen();
          school_header();
          cout << "\t\t1.Login as a Admin(Principle)?" << endl;
          cout << "\t\t2.Login as a Teacher?" << endl;
          cout << "\t\t3.Login as a student?" << endl;
          cout << " Press 4 to quite" << endl;

          // cout << " Enter your name" << endl;
          // cout << "Enter password" << endl;

          // to remove erorr from this we use char..
          cin >> option;
     } while (option != "3" && option != "1" && option != "2" && option != "4");
     return option;
}

//*******end of  main***************

void school_header()
{
     cout << "____________________________________________________________________" << endl;
     cout << endl;
     cout << "                      SCHOOL MANAGEMENT SYSTEM" << endl;
     cout << "____                                                           _____" << endl;
     cout << "____________________________________________________________________" << endl;
     cout << endl;
     cout << endl;
     cout << endl;
}

string admin_header() // priciple meanu
{
     string option;
     do
     {
          clear_screen();
          school_header();
          cout << "1.Manage teacher " << endl;     // done
          cout << "2.Manage Student " << endl;     // done
          cout << "3-Manage  subjects " << endl;   //
          cout << "4-Announce something " << endl; // just like a message sent to teacherzzz
          cout << "5- view attendencs and remaining fee of teacher" << endl;
          // cout << "6-Manage Instructions OR VIEW INSTRUCRON " << endl;
          cout << "6.5- view feed back from teacher " << endl;
          cout << "6-change password" << endl;
          cout << "7-Log Out " << endl;
          cout << "Enter option : ";
          cin >> option;
     } while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "6.5" && option != "7");

     return option;
}

string admin_manage_subject()
{
     string option;
     do
     {
          clear_screen();
          school_header();
          cout << "1-Add a subject " << endl;  // course name, cousre duration,done
          cout << "2-View  subjects" << endl;  // done
          cout << "3-Remove subjects" << endl; // krna ha
          cout << "4-Back to meanu" << endl;
          cin >> option;
     } while (option != "1" && option != "2" && option != "3" && option != "4");
     return option;
}

string admin_manage_staff()
{
     string option;
     do
     {

          clear_screen();
          school_header();
          cout << "1-Add staff?(TEACHING)" << endl;
          cout << "2-Remove staff" << endl;
          cout << "3-see  staff?" << endl;
          cout << "4-Add or update  salary of staff(TEACHING)" << endl;
          cout << "5-View salary of staff(asending vise sorting and decending wise sorting ) " << endl;
          cout << "6-Back To Menu " << endl;
          cin >> option;
     } while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6"); // && option != "7";
     return option;
}

string admin_manage_students() // teacher bhi yahi use ker skta ha
{
     string option;
     do
     {
          clear_screen();
          school_header();
          cout << "1-Add students" << endl;
          cout << "2-Remove student" << endl;
          cout << "3-see available students?(sorting  wise)" << endl;
          cout << "4-Back To Menu " << endl;
          cin >> option;
     } while (option != "1" && option != "2" && option != "3" && option != "4");
     return option;
}

void Add_student(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[])
{

     string s_name, f_name, password;
     float roll_no;
     int fee;
     float marks;
     gotoxy(1, 10);
     cout << "Student name";
     cin.ignore(); // <<endl;
     gotoxy(1, 11);
     getline(cin, s_name);
     gotoxy(20, 10);
     cout << "Father name";
     gotoxy(20, 11);
     getline(cin, f_name);
     // cin.ignore();
     gotoxy(40, 10);
     cout << "set pass word for student";
     gotoxy(40, 11);
     getline(cin, password);
     gotoxy(67, 10); // sort by price...
     cout << " Roll number>> ";
     // cin.ignore(); //<< endl;
     gotoxy(67, 11);
     cin >> roll_no;
     do
     {
          gotoxy(100, 10);
          cout << "FEE of student (per month)>> ";
          // cin.ignore(); //<< endl;
          gotoxy(100, 11);
          cin >> fee;
     } while (fee < 0);

     cin.ignore();
     do
     {
          marks = 0;
          gotoxy(130, 10);
          cout << "Marks in previous class ";
          // cin.ignore();
          gotoxy(130, 11);
          cin >> marks;
     } while (marks > 100);

     AddStudentIntoArr(s_name, f_name, password, roll_no, fee, marks, stu_count, stu_name, stu_f_name, password_for_student, stu_roll_num, stu_fee, stu_marks);
}
void AddStudentIntoArr(string s_name, string f_name, string password_for_studentt, float roll_no, int fee, float marks, int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[])
{
     stu_name[stu_count] = s_name;
     stu_f_name[stu_count] = f_name;
     password_for_student[stu_count] = password_for_studentt;
     stu_roll_num[stu_count] = roll_no;
     stu_fee[stu_count] = fee;
     stu_marks[stu_count] = marks;
}

// // for adding teacher
void Add_teacher(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{

     string tname, t_fname, tpassword, phone_no, addres, cnicc, account_noo;
     float salari;

     gotoxy(1, 10);

     cout << "Teacher  name " << endl;
     cin.ignore();
     gotoxy(1, 11);
     getline(cin, tname);

     gotoxy(17, 10);
     cout << "Father name " << endl;

     gotoxy(17, 11);
     getline(cin, t_fname);
     gotoxy(35, 10);
     cout << " set password for teacher" << endl;
     // cin.ignore();
     gotoxy(35, 11);
     getline(cin, tpassword);

     do
     {
          gotoxy(62, 10); // sort by price...
          cout << "Teacher phone number " << endl;

          gotoxy(62, 11); //<< endl;
          cin >> phone_no;
     } while (phone_no.length() != 11);

     gotoxy(80, 10);
     cout << "Address of teacher  " << endl;
     cin.ignore(); //<< endl;

     gotoxy(80, 11);
     getline(cin, addres);
     do
     {
          gotoxy(110, 10);
          cout << "cnic  of teacher  " << endl; //<< endl;

          gotoxy(110, 11);
          cin >> cnicc; //
     } while (cnicc.length() != 13);

     gotoxy(140, 10);
     cout << "account no of teacher" << endl;
     cin.ignore();

     gotoxy(140, 11);
     cin >> account_noo;
     do
     {
          gotoxy(175, 10);
          cout << "Enter the salary of teacher " << endl;

          gotoxy(175, 11);
          cin >> salari;
     } while (salari < 0);

     AddTeacheIntoArr(tname, t_fname, tpassword, phone_no, addres, cnicc, account_noo, salari, teacher_count, teacher_name, teacher_father_name, password_for_teacher, phone_number, address, cnic, account_no, salary);
}

void AddTeacheIntoArr(string tname, string t_fname, string tpassword, string phone_no, string addres, string cnicc, string account_noo, float salari, int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{
     teacher_name[teacher_count] = tname;
     teacher_father_name[teacher_count] = t_fname;
     password_for_teacher[teacher_count] = tpassword;
     phone_number[teacher_count] = phone_no;
     address[teacher_count] = addres;
     cnic[teacher_count] = cnicc;
     account_no[teacher_count] = account_noo;
     salary[teacher_count] = salari;
}
void Addsubject(int subject_count, string teacher_nameforsubject[], string subject[], string duration[])
{
     string te_name, sub_name, dura;

     gotoxy(1, 10);
     cout << "enter subject name" << endl;
     cin.ignore();
     gotoxy(1, 11);
     getline(cin, sub_name);
     // do{

     gotoxy(30, 10);
     cout << "enter teacher for it";
     gotoxy(30, 11);
     getline(cin, te_name);
     // }while(te_name!=teacher_name[i])
     gotoxy(60, 10);
     cout << "enter duration";
     gotoxy(60, 11);
     getline(cin, dura);

     addsubjectintoarr(sub_name, te_name, dura, subject_count, teacher_nameforsubject, subject, duration);
}
void addsubjectintoarr(string te_name, string sub_name, string dura, int subject_count, string teacher_nameforsubject[], string subject[], string duration[])
{
     teacher_nameforsubject[subject_count] = sub_name;
     subject[subject_count] = te_name;
     duration[subject_count] = dura;
}

void Add_marks_ofstudent(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[]) //, float subject_2_marks[], float subject_3_marks[], float subject_4_marks[], float subject_5_marks[])
{

     gotoxy(0, 9);
     cout << "Student name";

     gotoxy(25, 9);
     cout << "Father name";

     gotoxy(50, 9); // sort by price...
     cout << " Roll number>> ";

     gotoxy(75, 9);
     cout << "test marks ";

     int y = 11;
     float markk;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i];
          x = x + 25;
          gotoxy(x, y);
          cout << stu_f_name[i];
          x = x + 25;
          gotoxy(x, y);
          cout << stu_roll_num[i];
          x = x + 25;
          do
          {
               test_marks[i]=0;

               gotoxy(x, y);
               cin >> test_marks[i];
          } while (test_marks[i] > 100);
          y++;
     }
}

void Add_class_performance_marks(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[])
{

     gotoxy(0, 9);
     cout << "Student name";

     gotoxy(25, 9);
     cout << "Father name";

     gotoxy(50, 9); // sort by price...
     cout << " Roll number>> ";

     gotoxy(75, 9);
     cout << "class performance mark";

     int y = 11;
     float markk;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i];
          x = x + 25;
          gotoxy(x, y);
          cout << stu_f_name[i];
          x = x + 25;
          gotoxy(x, y);
          cout << stu_roll_num[i];
          x = x + 25;
          do
          {

               gotoxy(x, y);
               cin >> class_performance_marks[i];
          } while (class_performance_marks[i] > 100);
          y++;
     }
}

void viewlecture(int subject_count, string teacher_nameforsubject[], string subject[], string duration[])
{
     gotoxy(0, 9);
     cout << "teacher Name" << endl;
     gotoxy(30, 9);
     cout << "Subject Name" << endl;
     gotoxy(60, 9);
     cout << "duration" << endl;
     gotoxy(90, 9);
     int y = 11;
     for (int i = 0; i < subject_count; i++)
     {

          int x = 0;
          gotoxy(x, y);
          cout << teacher_nameforsubject[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << subject[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << duration[i] << endl;

          y++;
     }
}
void view_present_students(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int student_check[])
{
     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll num" << endl;
     gotoxy(90, 9);
     cout << "presence" << endl;

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          if (student_check[i] != 0)
          {
               gotoxy(x, y);
               cout << stu_name[i] << endl;
               x = x + 30;
               gotoxy(x, y);
               cout << stu_f_name[i] << endl;
               x = x + 30;
               gotoxy(x, y);
               cout << stu_roll_num[i] << endl;
               x = x + 30;

               gotoxy(x, y);
               cout << student_check[i] << endl;
               y++;
          }
          else if (student_check[i] == 0)
          {
               continue;
          }
     }
}

void view_absent_students(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int student_check[])
{
     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll num" << endl;
     gotoxy(90, 9);
     cout << "presence" << endl;

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          if (student_check[i] == 0)
          {
               int x = 0;
               gotoxy(x, y);
               cout << stu_name[i] << endl;
               x = x + 30;
               gotoxy(x, y);
               cout << stu_f_name[i] << endl;
               x = x + 30;
               gotoxy(x, y);
               cout << stu_roll_num[i] << endl;
               x = x + 30;

               gotoxy(x, y);
               cout << student_check[i] << endl;
               y++;
          }
     }
}
int max_salary_t(int s, int e, float salary[])
{

     int index = s;
     int largest = salary[s];
     for (int i = s; i < e; i++)
     {
          if (largest < salary[i])
          {
               largest = salary[i];
               index = i;
          }
     }
     return index;
}
// mini salray indexx finding
int mini_salary_t(int s, int e, float salary[])
{

     int index = s;
     int largest = salary[s];
     for (int i = s; i < e; i++)
     {
          if (largest > salary[i])
          {
               largest = salary[i];
               index = i;
          }
     }
     return index;
}
// for marks wise sort
int max_marks(int s, int e, float stu_marks[]) // done
{

     int index = s;
     int largest = stu_marks[s];
     for (int i = s; i < e; i++)
     {
          if (largest < stu_marks[i])
          {
               largest = stu_marks[i];
               index = i;
          }
     }
     return index;
}

int max_sub_marks(int s, int e, float test_marks[])
{
     int index = s;
     int largest = test_marks[s];
     for (int i = s; i < e; i++)
     {
          if (largest < test_marks[i])
          {
               largest = test_marks[i];
               index = i;
          }
     }
     return index;
}
void show_max_mark_in_sub(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[])
{
     string name, father_name;
     float rollno, marks;

     for (int i = 0; i < stu_count; i++)
     {

          int index = max_sub_marks(i, stu_count, test_marks);

          name = stu_name[i];
          stu_name[i] = stu_name[index];
          stu_name[index] = name;

          father_name = stu_f_name[i];
          stu_f_name[i] = stu_f_name[index];
          stu_f_name[index] = father_name;

          rollno = stu_roll_num[i];
          stu_roll_num[i] = stu_roll_num[index];
          stu_roll_num[index] = rollno;

          marks = test_marks[i];
          test_marks[i] = test_marks[index];
          test_marks[index] = marks;
     }

     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll number" << endl;
     gotoxy(90, 9);
     cout << "student Marks" << endl;

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_f_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_roll_num[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << test_marks[i] << endl;

          y++;
     }
}
int max_performance_marks(int s, int e, float class_performance_marks[])
{
     int index = s;
     int largest = class_performance_marks[s];
     for (int i = s; i < e; i++)
     {
          if (largest < class_performance_marks[i])
          {
               largest = class_performance_marks[i];
               index = i;
          }
     }
     return index;
}
void show_max_mark_in_class_performance(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[])
{
     string name, father_name;
     float rollno, marks;

     for (int i = 0; i < stu_count; i++)
     {

          int index = max_performance_marks(i, stu_count, class_performance_marks);

          name = stu_name[i];
          stu_name[i] = stu_name[index];
          stu_name[index] = name;

          father_name = stu_f_name[i];
          stu_f_name[i] = stu_f_name[index];
          stu_f_name[index] = father_name;

          rollno = stu_roll_num[i];
          stu_roll_num[i] = stu_roll_num[index];
          stu_roll_num[index] = rollno;

          marks = class_performance_marks[i];
          class_performance_marks[i] = class_performance_marks[index];
          class_performance_marks[index] = marks;
     }

     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll number" << endl;
     gotoxy(90, 9);
     cout << "student Marks" << endl;

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_f_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_roll_num[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << class_performance_marks[i] << endl;

          y++;
     }
}

int mini_marks(int s, int e, float stu_marks[]) // done
{

     int index = s;
     int largest = stu_marks[s];
     for (int i = s; i < e; i++)
     {
          if (largest > stu_marks[i])
          {
               largest = stu_marks[i];
               index = i;
          }
     }
     return index;
}

void sort_wrt_max_marks(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int stu_fee[], float stu_marks[])
{
     string name, father_name;
     float rollno, marks;
     int fee;
     for (int i = 0; i < stu_count; i++)
     {

          int index = max_marks(i, stu_count, stu_marks);

          name = stu_name[i];
          stu_name[i] = stu_name[index];
          stu_name[index] = name;

          father_name = stu_f_name[i];
          stu_f_name[i] = stu_f_name[index];
          stu_f_name[index] = father_name;

          rollno = stu_roll_num[i];
          stu_roll_num[i] = stu_roll_num[index];
          stu_roll_num[index] = rollno;

          marks = stu_marks[i];
          stu_marks[i] = stu_marks[index];
          stu_marks[index] = marks;

          fee = stu_fee[i];
          stu_fee[i] = stu_fee[index];
          stu_fee[index] = fee;
     }

     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll number" << endl;
     gotoxy(90, 9);
     cout << "student fee" << endl;
     gotoxy(120, 9);
     cout << "Student Marks" << endl;
     gotoxy(150, 9);

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_f_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_roll_num[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_fee[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_marks[i] << endl;

          y++;
     }
}

void sort_wrt_mini_marks(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int stu_fee[], float stu_marks[])
{
     string name, father_name;
     float rollno, marks;
     int fee;
     for (int i = 0; i < stu_count; i++)
     {

          int index = mini_marks(i, stu_count, stu_marks);

          name = stu_name[i];
          stu_name[i] = stu_name[index];
          stu_name[index] = name;

          father_name = stu_f_name[i];
          stu_f_name[i] = stu_f_name[index];
          stu_f_name[index] = father_name;

          rollno = stu_roll_num[i];
          stu_roll_num[i] = stu_roll_num[index];
          stu_roll_num[index] = rollno;

          marks = stu_marks[i];
          stu_marks[i] = stu_marks[index];
          stu_marks[index] = marks;

          fee = stu_fee[i];
          stu_fee[i] = stu_fee[index];
          stu_fee[index] = fee;
     }

     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll number" << endl;
     gotoxy(90, 9);
     cout << "student fee" << endl;
     gotoxy(120, 9);
     cout << "Student Marks" << endl;
     gotoxy(150, 9);

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_f_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_roll_num[i] << endl;
          x = x + 30;
          cout << stu_fee[i] << endl;
          gotoxy(x, y);
          x = x + 30;
          cout << stu_marks[i] << endl;

          y++;
     }
}

void sort_wrt_max_salary(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{
     string teacher_namee, t_f_name, phone_num, adres, cnicc, account_noo, password;
     float salari;

     for (int i = 0; i < teacher_count; i++)
     {
          int index = max_salary_t(i, teacher_count, salary);

          teacher_namee = teacher_name[i];
          teacher_name[i] = teacher_name[index];
          teacher_name[index] = teacher_namee;

          t_f_name = teacher_father_name[i];
          teacher_father_name[i] = teacher_father_name[index];
          teacher_father_name[index] = t_f_name;

          password = password_for_teacher[i];
          password_for_teacher[i] = password_for_teacher[index];
          password_for_teacher[index] = password;

          phone_num = phone_number[i];
          phone_number[i] = phone_number[index];
          phone_number[index] = phone_num;

          adres = address[i];
          address[i] = address[index];
          address[index] = adres;

          cnicc = cnic[i];
          cnic[i] = cnic[index];
          cnic[index] = cnicc;

          account_noo = account_no[i];
          account_no[i] = account_no[index];
          account_no[index] = account_noo;

          salari = salary[i];
          salary[i] = salary[index];
          salary[index] = salari;
     }

     gotoxy(0, 9);
     cout << "Teacher Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "phone number" << endl;
     gotoxy(90, 9);
     cout << "Adress" << endl;
     gotoxy(120, 9);
     cout << "CNIC" << endl;
     gotoxy(150, 9);
     cout << "Accout no" << endl;
     gotoxy(180, 9);
     cout << "Salary" << endl;
     gotoxy(210, 9);

     int y = 11;
     for (int i = 0; i < teacher_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << teacher_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << teacher_father_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << phone_number[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << address[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << cnic[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << account_no[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << salary[i] << endl;

          y++;
     }
}
void sort_wrt_mini_salary(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{
     string teacher_namee, t_f_name, phone_num, cnicc, account_noo, password;
     string adres;
     float salari = 0;

     for (int i = 0; i < teacher_count; i++)
     {
          int index = mini_salary_t(i, teacher_count, salary);

          teacher_namee = teacher_name[i];
          teacher_name[i] = teacher_name[index];
          teacher_name[index] = teacher_namee;

          t_f_name = teacher_father_name[i];
          teacher_father_name[i] = teacher_father_name[index];
          teacher_father_name[index] = t_f_name;

          password = password_for_teacher[i];
          password_for_teacher[i] = password_for_teacher[index];
          password_for_teacher[index] = password;

          phone_num = phone_number[i];
          phone_number[i] = phone_number[index];
          phone_number[index] = phone_num;

          adres = address[i];
          address[i] = address[index];
          address[index] = adres;

          cnicc = cnic[i];
          cnic[i] = cnic[index];
          cnic[index] = cnicc;

          account_noo = account_no[i];
          account_no[i] = account_no[index];
          account_no[index] = account_noo;

          salari = salary[i];
          salary[i] = salary[index];
          salary[index] = salari;
     }

     gotoxy(0, 9);
     cout << "Teacher Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "phone number" << endl;
     gotoxy(90, 9);
     cout << "Adress" << endl;
     gotoxy(120, 9);
     cout << "CNIC" << endl;
     gotoxy(150, 9);
     cout << "Accout no" << endl;
     gotoxy(180, 9);
     cout << "Salary" << endl;
     gotoxy(210, 9);
     // cout<<teacher_count<<endl;
     int y = 11;
     for (int i = 0; i < teacher_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << teacher_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << teacher_father_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << phone_number[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << address[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << cnic[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << account_no[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << salary[i] << endl;

          y++;
     }
}

void update_salary(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{
     float new_salary;
     string teacher_n;
     bool flag = false;
     cout << "Enter the name of teacher" << endl;
     cin.ignore();
     getline(cin, teacher_n);
     for (int i = 0; i < teacher_count; i++)
     {
          if (teacher_n == teacher_name[i])
          {
               cout << "Enter the salry for teacher";
               cin >> new_salary;

               salary[i] = salary[i] + new_salary;
               flag = true;
          }
     }
     if (flag == true)
     {
          flag = false;
     }
     else
     {
          cout << " Sorry ! teacher is not in ur data." << endl;
          flag = false;
     }
}

bool deduct_salary(int teacher_count, string teacher_name[], float salary[])
{
     int absents;
     string tee_name;
     bool flag = false;
     cout << "enter teacher name" << endl;
     cin.ignore();
     getline(cin, tee_name);
     for (int i = 0; i < teacher_count; i++)
     {
          if (tee_name == teacher_name[i])
          {
               cout << "enter the absents of teacher" << endl;
               cin.ignore();
               cin >> absents;
               if (absents > 3)
               {
                    salary[i] = salary[i] - fabs(absents * 300);
               }

               flag = true;
          }
     }
     if (flag == true)
     {
          flag = false;
     }
     else
     {
          cout << " Sorry ! teacher is not in ur data." << endl;
          flag = false;
     }
}

bool remove_student(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[])
{
     bool flag = false;
     string s_name;
     cout << "enter the student name " << endl;
     cin.ignore();
     getline(cin, s_name);
     for (int i = 0; i < stu_count; i++)
     {
          if (s_name == stu_name[i])
          {

               for (int k = i; k < stu_count; k++)
               {
                    stu_name[i] = stu_name[i + 1];
                    stu_f_name[i] = stu_f_name[i + 1];
                    stu_roll_num[i] = stu_roll_num[i + 1];
                    stu_fee[i] = stu_fee[i + 1];
                    stu_marks[i] = stu_marks[i + 1];
               }
               flag = true;
          }
     }
     if (flag == true)
     {
          flag = false;
     }
     else
     {
          cout << " Sorry ! student  is not in ur data." << endl;
          flag = false;
     }
}

bool remove_teacher(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{
     bool flage = false;
     string t_name;
     cout << "enter the teacher name " << endl;
     cin.ignore();
     getline(cin, t_name);
     for (int i = 0; i < teacher_count; i++)
     {
          if (t_name == teacher_name[i])
          {

               for (int k = i; k < teacher_count; k++)
               {
                    teacher_name[i] = teacher_name[i + 1];
                    teacher_father_name[i] = teacher_father_name[i + 1];
                    phone_number[i] = phone_number[i + 1];
                    address[i] = address[i + 1];
                    cnic[i] = cnic[i + 1];
                    account_no[i] = account_no[i + 1];
                    salary[i] = salary[i + 1];
               }
               flage = true;
          }
     }
     if (flage == true)
     {
          flage = false;
     }
     else
     {
          cout << " Sorry ! student  is not in ur data." << endl;
          flage = false;
     }
}
bool remove_subject(int subject_count, string teacher_nameforsubject[], string subject[], string duration[])
{

     bool flage = false;
     string subb_name;
     cout << "enter the subject name " << endl;
     cin.ignore();
     getline(cin, subb_name);
     for (int i = 0; i < subject_count; i++)
     {
          if (subb_name == subject[i])
          {

               for (int k = i; k < subject_count; k++)
               {
                    teacher_nameforsubject[i] = teacher_nameforsubject[i + 1];
                    subject[i] = subject[i + 1];
                    duration[i] = duration[i + 1];
               }
               flage = true;
          }
     }
     if (flage == true)
     {
          flage = false;
     }
     else
     {
          cout << " Sorry ! subject  is not in ur data." << endl;
          flage = false;
     }
}

void attendence_of_student(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], int student_check[])
{

     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll number" << endl;
     gotoxy(90, 9);
     cout << "attendence" << endl;
     // int chk;
     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_f_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_roll_num[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cin >> student_check[i];

          y++;
          // add_student_attendenceintoarr(chk, stu_count, student_check);
     }
     //
}

void teacher_header()
{
     cout << "\t\t______________________" << endl;
     cout << "\t\t        Teacher       " << endl;
     cout << "\t\t______________________" << endl;
}

void calculate_aggregate(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[], float test_marks[], float aggrigate[])
{

     // 20% weigtage for test marks && 80% weightage of class performance

     for (int i = 0; i < stu_count; i++)
     {
          aggrigate[i] = ((class_performance_marks[i] * 80) / 100) + ((test_marks[i] * 20) / 100);
     }
}
int check_max_aggrigate(int s, int e, float aggrigate[])
{
     int index = s;
     int largest = aggrigate[s];
     for (int i = s; i < e; i++)
     {
          if (largest < aggrigate[i])
          {
               largest = aggrigate[i];
               index = i;
          }
     }
     return index;
}

void merit_list(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[], float class_performance_marks[], float aggrigate[])
{

     string name, father_name;
     float rollno, testmarks, performamarks, agg;

     for (int i = 0; i < stu_count; i++)
     {

          int index = check_max_aggrigate(i, stu_count, aggrigate);

          name = stu_name[i];
          stu_name[i] = stu_name[index];
          stu_name[index] = name;

          father_name = stu_f_name[i];
          stu_f_name[i] = stu_f_name[index];
          stu_f_name[index] = father_name;

          rollno = stu_roll_num[i];
          stu_roll_num[i] = stu_roll_num[index];
          stu_roll_num[index] = rollno;

          testmarks = test_marks[i];
          test_marks[i] = test_marks[index];
          test_marks[index] = testmarks;

          performamarks = class_performance_marks[i];
          class_performance_marks[i] = class_performance_marks[index];
          class_performance_marks[index] = performamarks;

          agg = aggrigate[i];
          aggrigate[i] = aggrigate[index];
          aggrigate[index] = agg;
     }

     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll number" << endl;
     gotoxy(90, 9);
     cout << "Test Marks" << endl;
     gotoxy(120, 9);
     cout << "class performa number" << endl;
     gotoxy(150, 9);
     cout << "aggrigate" << endl;

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_f_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_roll_num[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << test_marks[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << class_performance_marks[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << aggrigate[i] << endl;

          y++;
     }
}

// void view_teacer_his_own_profie(string tname,string teacher)///
void view_teacer_his_own_profie(string tname, string password, int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{
     for (int i = 0; i < teacher_count; i++)
     {
          if (tname == teacher_name[i] && password == password_for_teacher[i])
          {

               gotoxy(0, 9);
               cout << "Teacher Name" << endl;
               gotoxy(30, 9);
               cout << "Father Name" << endl;
               gotoxy(60, 9);
               cout << "phone number" << endl;
               gotoxy(90, 9);
               cout << "Adress" << endl;
               gotoxy(120, 9);
               cout << "CNIC" << endl;
               gotoxy(150, 9);
               cout << "Accout no" << endl;
               gotoxy(180, 9);
               cout << "Salary" << endl;
               // gotoxy(210, 9);

               gotoxy(0, 11);
               cout << teacher_name[i] << endl;

               gotoxy(30, 11);
               cout << teacher_father_name[i] << endl;

               gotoxy(60, 11);
               cout << phone_number[i] << endl;

               gotoxy(90, 11);
               cout << address[i] << endl;

               gotoxy(120, 11);
               cout << cnic[i] << endl;

               gotoxy(150, 11);
               cout << account_no[i] << endl;

               gotoxy(180, 11);
               cout << salary[i] << endl;
          }
     }
}
void see_class_performance_speciic(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[])
{
     float roll_no;
     gotoxy(40, 30);
     cout << "Enter the roll number of student" << endl;
     cin.ignore();
     gotoxy(40, 31);
     cin >> roll_no;

     for (int i = 0; i < stu_count; i++)
     {
          if (roll_no == stu_roll_num[i])
          {
               gotoxy(0, 9);
               cout << "student Name" << endl;
               gotoxy(30, 9);
               cout << "Father Name" << endl;
               gotoxy(60, 9);
               cout << "roll number" << endl;
               gotoxy(90, 9);
               cout << "class performance" << endl;

               gotoxy(0, 11);
               cout << stu_name[i] << endl;

               gotoxy(30, 11);
               cout << stu_f_name[i] << endl;

               gotoxy(60, 11);
               cout << stu_roll_num[i] << endl;

               gotoxy(90, 11);
               cout << class_performance_marks[i] << endl;
          }
     }
}

string teacher_meanu()
{
     string teac_meanu_option;
     do
     {
          clear_screen();
          school_header();
          cout << "0.1- see profile" << endl;        // kerna ha
          cout << "1-take atteandenc?" << endl;      // (done)       // add , remove , del opiton me
          cout << "2-view present students" << endl; // admin na jo time table dala ho ga
          cout << "3-view absent students" << endl;  // teacher can't manage timetab
          cout << "4-Add  test marks  of student " << endl;
          cout << "4.5-view  test marks of students" << endl; // uska name pochin>> subject+
          cout << "5-class performance marks" << endl;
          cout << "5.5-view classperformance marks " << endl;
          cout << "5.6- calculate the aggregate of student" << endl;
          cout << "6-Generate merit list" << endl;
          cout << "7-see class performance of specific student" << endl;
          cout << "8- view announcememt from  admin" << endl; // and he can rply bto him yea. good feacture
          cout << "8.8- Announcement to class" << endl;
          cout << "9-view feedback from student " << endl;
          cout << "9.5 answer to princple" << endl;
          cout << "9.9 - see statistics of test marks" << endl;                // kerna ha bro
          cout << "9.10 - see staticstics of class performance amrks" << endl; // kerna ha bro  //like search a student like this
          cout << "10-log out ?" << endl;
          cin >> teac_meanu_option;

     } while (teac_meanu_option != "1" && teac_meanu_option != "0.1" && teac_meanu_option != "2" && teac_meanu_option != "3" && teac_meanu_option != "4" && teac_meanu_option != "5" && teac_meanu_option != "5.5" && teac_meanu_option != "5.6" && teac_meanu_option != "6" && teac_meanu_option != "7" && teac_meanu_option != "8" && teac_meanu_option != "9" && teac_meanu_option != "6.5" && teac_meanu_option != "10" && teac_meanu_option != "4.5" && teac_meanu_option != "8.8" && teac_meanu_option != "9.10" && teac_meanu_option != "9.9" && teac_meanu_option != "9.5");

     return teac_meanu_option;
}
string manage_student() // this is for teacher
{
     string option;
     do
     {
          clear_screen();
          cout << "1-Add student" << endl;
          cout << "2-View stduents" << endl;
          cout << "3-Search student" << endl;
          cout << "4-Remove student" << endl;
          cout << "5-back to menu" << endl;

          cin >> option;

     } while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5");

     return option;
}
// void student_header(string name) kerna ha mojha
void student_header()
{
     cout << "\t\t______________________" << endl;
     cout << "\t\t        Student       " << endl;
     cout << "\t\t______________________" << endl;
}
string student_menu()
{
     string option;
     do
     {
          clear_screen();
          school_header();
          cout << "1-check Profile" << endl;   // attendences , marks , absents ,
          cout << "2-view fee chalan" << endl; // view name and his fee added by admin
          cout << "3-view result" << endl;     // marks , result me dekhna a teacher na result announce kia ha ya nahi
          cout << "3.3view result of whole classs" << endl;
          // cout << "4-view time table" << endl;
          cout << "4.5 notification from teacher" << endl;
          cout << "5-give a comment to teacher" << endl; // filehadling
          // cout << "6-view courses" << endl;    // math ,scince,geography,
          // cout << "7-Register a course" << endl;
          cout << "6-Exit" << endl;
          cin >> option;
     } while (option != "1" && option == "2" && option != "3" && option != "4" && option != "5" && option == "6" && option != "3.3" && option != "4.5");
     return option;
}

void clear_screen()
{
     system("cls");
}
void anyword()
{
     cout << "Press any key to continue : ";
     getch();
}
void gotoxy(int x, int y)
{
     COORD coordinates; // coordinates is declared as COORD
     coordinates.X = x; // defining x-axis
     coordinates.Y = y; // defining  y-axis
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void see_his_own_result(string s_namee, string s_password, int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], float test_marks[], float class_performance_marks[], float aggrigate[])
{
     for (int i = 0; i < stu_count; i++)
     {
          if (s_namee == stu_name[i] && s_password == password_for_student[i])
          {
               gotoxy(0, 9);
               cout << "student Name" << endl;
               gotoxy(30, 9);
               cout << "Father Name" << endl;
               gotoxy(60, 9);
               cout << "Roll number" << endl;
               gotoxy(90, 9);
               cout << "Test Marks" << endl;
               gotoxy(120, 9);
               cout << "class performa number" << endl;
               gotoxy(150, 9);
               cout << "aggrigate" << endl;

               gotoxy(0, 10);
               cout << stu_name[i] << endl;

               gotoxy(30, 10);
               cout << stu_f_name[i] << endl;

               gotoxy(60, 10);
               cout << stu_roll_num[i] << endl;

               gotoxy(90, 10);
               cout << test_marks[i] << endl;

               gotoxy(120, 10);
               cout << class_performance_marks[i] << endl;

               gotoxy(150, 10);
               cout << aggrigate[i] << endl;
          }
     }
}
void view_student_own_profile(string s_namee, string s_password, int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], string password_for_student[])
{
     for (int i = 0; i < stu_count; i++)
     {
          if (s_namee == stu_name[i] && s_password == password_for_student[i])
          {
               gotoxy(0, 9);
               cout << "student Name" << endl;
               gotoxy(30, 9);
               cout << "Father Name" << endl;
               gotoxy(60, 9);
               cout << "Roll number" << endl;
               gotoxy(90, 9);
               cout << "student password" << endl;

               gotoxy(0, 10);
               cout << stu_name[i] << endl;

               gotoxy(30, 10);
               cout << stu_f_name[i] << endl;

               gotoxy(60, 10);
               cout << stu_roll_num[i] << endl;

               gotoxy(90, 10);
               cout << password_for_student[i] << endl;
          }
     }
}
// SetConsoleTextAttribute(h, 11);

// lemme changes
//*************** file handling ******************
void add_student_intofile(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[])
{
     fstream myfile;
     myfile.open("addstudentintofile.txt", ios::out);
     for (int i = 0; i < stu_count - 1; i++) // stu_count-1
     {
          myfile << stu_name[i] << "," << stu_f_name[i] << "," << password_for_student[i] << "," << stu_roll_num[i] << "," << stu_fee[i] << "," << stu_marks[i] << endl;
     }
     myfile << stu_name[stu_count - 1] << "," << stu_f_name[stu_count - 1] << "," << password_for_student[stu_count - 1] << "," << stu_roll_num[stu_count - 1] << "," << stu_fee[stu_count - 1] << "," << stu_marks[stu_count - 1];
     myfile.close();
}
void add_teacher_intofile(int teacher_count, string teacher_name[], string teacher_father_name[], string password_for_teacher[], string phone_number[], string address[], string cnic[], string account_no[], float salary[])
{
     fstream myfile;
     myfile.open("addteacherintofile.txt", ios::out);
     for (int i = 0; i < teacher_count - 1; i++)
     {
          myfile << teacher_name[i] << "," << teacher_father_name[i] << "," << password_for_teacher[i] << "," << phone_number[i] << "," << address[i] << "," << cnic[i] << "," << account_no[i] << "," << salary[i] << endl;
     }
     myfile << teacher_name[teacher_count - 1] << "," << teacher_father_name[teacher_count - 1] << "," << password_for_teacher[teacher_count - 1] << "," << phone_number[teacher_count - 1] << "," << address[teacher_count - 1] << "," << cnic[teacher_count - 1] << "," << account_no[teacher_count - 1] << "," << salary[teacher_count - 1];
     myfile.close();
}
void add_subject_intofile(int subject_count, string teacher_nameforsubject[], string subject[], string duration[])
{
     fstream myfile;
     myfile.open("addsubjectintofile.txt", ios::out);
     for (int i = 0; i < subject_count - 1; i++)
     {
          myfile << teacher_nameforsubject[i] << "," << subject[i] << "," << duration[i] << endl;
     }
     myfile << teacher_nameforsubject[subject_count - 1] << "," << subject[subject_count - 1] << "," << duration[subject_count - 1];
     myfile.close();
}
void add_test_marks_intoFile(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float test_marks[])
{
     fstream myfile;
     myfile.open("addtestintofile.txt", ios::out);
     for (int i = 0; i < stu_count - 1; i++)
     {
          myfile << stu_name[i] << "," << stu_f_name[i] << "," << stu_roll_num[i] << "," << test_marks[i] << endl;
     }
     myfile << stu_name[stu_count - 1] << "," << stu_f_name[stu_count - 1] << "," << stu_roll_num[stu_count - 1] << "," << test_marks[stu_count - 1];
     myfile.close();
}
void Add_class_performance_marksintofile(int stu_count, string stu_name[], string stu_f_name[], float stu_roll_num[], float class_performance_marks[])
{
     fstream myfile;
     myfile.open("AddCPintofile.txt", ios::out);
     for (int i = 0; i < stu_count - 1; i++)
     {
          myfile << stu_name[i] << "," << stu_f_name[i] << "," << stu_roll_num[i] << "," << class_performance_marks[i] << endl;
     }
     myfile << stu_name[stu_count - 1] << "," << stu_f_name[stu_count - 1] << "," << stu_roll_num[stu_count - 1] << "," << class_performance_marks[stu_count - 1];
     myfile.close();
}

string parseData(string record, int field)
{
     int comma = 1;
     string item = "";
     for (int x = 0; x < record.length(); x++)
     {
          if (record[x] == ',')
          {
               comma = comma + 1;
          }
          else if (comma == field)
          {
               item = item + record[x];
          }
     }
     return item;
}
int load_stu_data(int stu_count, string stu_name[], string stu_f_name[], string password_for_student[], float stu_roll_num[], int stu_fee[], float stu_marks[])
{
     fstream f;
     string record;
     f.open("addstudentintofile.txt", ios::in);
     if (!f)
     {
          cout << "file not found";
     }
     else
     {
          while (!(f.eof()))
          {
               getline(f, record);
               if (record != "")
               {
                    stu_name[stu_count] = parseData(record, 1);
                    stu_f_name[stu_count] = parseData(record, 2);
                    password_for_student[stu_count] = parseData(record, 3);
                    stu_roll_num[stu_count] = stoi(parseData(record, 4));
                    stu_fee[stu_count] = stoi(parseData(record, 5));
                    stu_marks[stu_count] = stoi(parseData(record, 6));
                    stu_count++;
               }
          }
          f.close();
          return stu_count;
     }

     
     gotoxy(0, 9);
     cout << "student Name" << endl;
     gotoxy(30, 9);
     cout << "Father Name" << endl;
     gotoxy(60, 9);
     cout << "Roll number" << endl;
     gotoxy(90, 9);
     cout << "student fee" << endl;
     gotoxy(120, 9);
     cout << "Student Marks" << endl;
     gotoxy(150, 9);

     int y = 11;
     for (int i = 0; i < stu_count; i++)
     {
          int x = 0;
          gotoxy(x, y);
          cout << stu_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_f_name[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_roll_num[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_fee[i] << endl;
          x = x + 30;
          gotoxy(x, y);
          cout << stu_marks[i] << endl;

          y++;
     }

     // return stu_count;
}

void Add_stu_msg_to_teacher_intofile(int stu_count, string feedback_from_student[])
{
     fstream myfile;
     myfile.open("addfeedback_from_studentintofile.txt", ios::out);
     for (int i = 0; i < stu_count - 1; i++)
     {
          myfile << feedback_from_student[i] << endl;
     }
     myfile << feedback_from_student[stu_count - 1];
     myfile.close();
}

void add_teacher_rpl__to_admin_intofile(int teacher_count, string messge_from_teacher[])
{
     fstream myfile;
     myfile.open("add_teacher_rpl__to_admin_intofile.txt", ios::out);
     for (int i = 0; i < teacher_count - 1; i++)
     {
          myfile << messge_from_teacher[i] << endl;
     }
     myfile << messge_from_teacher[teacher_count - 1];
     myfile.close();
}

void teacher_aanouncement(int teacher_count, string msg)
{
     fstream myfile;
     myfile.open("teacher_announcement.txt", ios::out);
     myfile << msg;
     myfile.close();
}

void statsistics_of_class_performance(int stu_count, float class_performance_marks[])
{

     int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
     for (int i = 0; i < stu_count; i++)
     {
          if (class_performance_marks[i] <= 20)
          {
               count1++;
          }
     }

     gotoxy(0, 10);
     cout << "students having marks lesser than 20%";
     gotoxy(50, 10);
     for (int i = 0; i < count1; i++)
     {

          cout << "*";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (class_performance_marks[i] > 20 && class_performance_marks[i] <= 40)
          {
               count2++;
          }
     }
     gotoxy(0, 11);
     cout << "students having marks lesser than 60% && > 40%";
     gotoxy(50, 11);
     ;
     for (int i = 0; i < count2; i++)
     {
          cout << "**";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (class_performance_marks[i] > 40 && class_performance_marks[i] <= 60)
          {
               count3++;
          }
     }
     gotoxy(0, 12);
     cout << "students having marks lesser than 80% && > 60%";
     gotoxy(50, 12);
     // gotoxy(5, 12);
     for (int i = 0; i < count3; i++)
     {
          cout << "**";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (class_performance_marks[i] > 60 && class_performance_marks[i] <= 80)
          {
               count4++;
          }
     }
     // gotoxy(5, 12);
     gotoxy(0, 13);
     cout << "students having marks lesser than 60% && > 40%";
     gotoxy(50, 13);
     for (int i = 0; i < count4; i++)
     {
          cout << "**";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (class_performance_marks[i] > 80)
          {
               count5++;
          }
     }
     gotoxy(0, 14);
     cout << "students having marks lesser than 40% && > 20%";
     gotoxy(50, 14);
     for (int i = 0; i < count5; i++)
     {
          cout << "**";
     }
     cout << endl;
}

void see_statistics_of_test_marks(int stu_count, float test_marks[])
{

     int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
     for (int i = 0; i < stu_count; i++)
     {
          if (test_marks[i] <= 20)
          {
               count1++;
          }
     }
     gotoxy(0, 10);
     cout << "students having marks lesser than 20%";
     gotoxy(50, 10);
     for (int i = 0; i < count1; i++)
     {

          cout << "*";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (test_marks[i] > 20 && test_marks[i] <= 40)
          {
               count2++;
          }
     }
     gotoxy(0, 11);
     cout << "students having marks lesser than 60% && > 40%";
     gotoxy(50, 11);
     for (int i = 0; i < count2; i++)
     {
          cout << "**";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (test_marks[i] > 40 && test_marks[i] <= 60)
          {
               count3++;
          }
     }
     gotoxy(0, 12);
     cout << "students having marks lesser than 80% && > 60%";
     gotoxy(50, 12);
     // gotoxy(5, 12);
     for (int i = 0; i < count3; i++)
     {
          cout << "**";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (test_marks[i] > 60 && test_marks[i] <= 80)
          {
               count4++;
          }
     }
     gotoxy(0, 13);
     cout << "students having marks lesser than 60% && > 40%";
     gotoxy(50, 13);
     for (int i = 0; i < count4; i++)
     {
          cout << "**";
     }

     for (int i = 0; i < stu_count; i++)
     {
          if (test_marks[i] > 80)
          {
               count5++;
          }
     }
     gotoxy(0, 14);
     cout << "students having marks lesser than 40% && > 20%";
     gotoxy(50, 14);
     for (int i = 0; i < count5; i++)
     {
          cout << "**";
     }
     cout << endl;
}