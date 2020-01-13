#include <iostream>
#include <fstream>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct time{
int quantity[10];
int model_list[10];
int branch_list[10];
int product_information[10][10][10];
};
time pre_molap[10][10][10];
struct m1{
    int quantity;

    int total_revenue;
};

m1 molap1[10][10][10];
struct p_m{
  int price;
  int product_id;

};
p_m product_model[10][10];

struct l_b{
int branch_id;
};
l_b location_branch[10][10];
struct ft
{
   int final_quantity;
   int final_revenue;
};
ft fact_table[1000];
// shipping structure
struct s_time
{
   int product_id[10];
   //int shipper_key[10];
   int from_location[10];
   int to_location[10];
   int units_shipped[10];
   int cost_per_shipped[10];
};
s_time shipping[10][10][10];
struct sp
{
  int shipper_id;
}; sp shipper_name[10];
struct s_molap
{
  int shipping_quantity;
  int total_shipping_cost;
};
s_molap shipping_molap[10][10][10];

struct product_available
{
   int available_product_id[10];
   int available_product_units[10];
   int required_product_id[10];
   int required_product_units[10];

} ;
product_available available[10][10][10];
struct pro_cost
{
  int product_id;
  int production_cost;

};
pro_cost production_cost[10][10];

struct pre_production
{
   int product_id[10];
   int product_units[10];
   int production_cost[10];
};
pre_production pre_production_molap[10][10][10];
struct p_molap
{
    int total_quantity;
    int total_production_cost;
};
p_molap production_molap[10][10][10];


    string product_name[10]={"Mobile","Computer","TV","Freeze","Motor","Fan","Car","RAM","CPU","Watch"};
    string model_name[10]={"M0","M1","M2","M3","M4","M5","M6","M7","M8","M9"};
    string location_name[10]={"Dhaka","Khulna","Rajshahi","Chittagong","Sylhet","Barisal","Rangpur","Jessore","Mymensingh","Bogra"};
    string branch_name[10]={"B0","B1","B2","B3","B4","B5","B6","B7","B8","B9"};
    string week[4]={"Week1","Week2","Week3","Week4"};
    string month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    string year[10]={"2007","2008","2009","2010","2011","2012","2013","2014","2015","2016"};
    string mapping_product_name(int a)
{
  int x=a;
  string s1;
  for(int i=0;i<10;i++)
  {
    if(x==i)
    {
      s1=product_name[i];
    }
  }
  return s1;
}
    string mapping_model_name(int a)
{
  int x=a;
  string s1;
  for(int i=0;i<10;i++)
  {
    if(x==i)
    {
      s1=model_name[i];
    }
  }
  return s1;
}
string mapping_location_name(int a)
{
      int x=a;
  string s1;
  for(int i=0;i<10;i++)
  {
    if(x==i)
    {
      s1=location_name[i];
    }
  }
  return s1;
}
string mapping_branch_name(int a)
{
      int x=a;
  string s1;
  for(int i=0;i<10;i++)
  {
    if(x==i)
    {
      s1=branch_name[i];
    }
  }
  return s1;
}
string mapping_week_name(int a)
{
   string s1;
   int x=a%4;
   s1=week[x];
   return s1;
}
string mapping_month_name(int a)
{
    string s1;
    int x=a;
    s1=month[x];
    return s1;
}
string mapping_year_name(int a)
{
    string s1;
    int x=a;
    s1=year[x];
    return s1;
}
void join()
{

    ofstream output_join("join_output.txt");
    output_join<<"Product id:"<<"   "<<"Product_name:"<<"     "<<"Model_name:"<<endl;
        for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        for(int k=0;k<10;k++)
      {

          for(int m=0;m<10;m++)
          {

             for(int x=0;x<10;x++)
             for(int y=0;y<10;y++)
             {
           if((pre_molap[i][j][k].model_list[m])==(product_model[x][y].product_id))
            {
               output_join<<pre_molap[i][j][k].model_list[m]<<"              "<<mapping_product_name(x)<<"            "<<mapping_model_name(y)<<"   "<<endl;
            }
            }

          }
        }
}
void join2()
{
        ofstream join("join_test.txt");
    join<<"Product id:"<<"   "<<"Product_name:"<<"     "<<"Model_name:"<<endl;
        for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        for(int k=0;k<10;k++)
      {

          for(int m=0;m<10;m++)
          {

             for(int x=0;x<10;x++)
             for(int y=0;y<10;y++)
             {
            if((pre_molap[i][j][k].model_list[m])==(product_model[x][y].product_id))
            {
               join<<pre_molap[i][j][k].model_list[m]<<"              "<<mapping_product_name(x)<<"            "<<mapping_model_name(y)<<"   "<<endl;
            }

            }

          }
        }
}
void join_with_location()
{
    int coun=0;
      ofstream output_join_loaction("join_with_location_output.txt");
    output_join_loaction<<"Branch id:"<<"   "<<"Location_name:"<<"     "<<"Branch_name:"<<"   "<<"Product_name:"<<"  "<<"Model_name:"<<"   "<<"Quantity:"<<endl;
        for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        for(int k=0;k<10;k++)
      {

          for(int m=0;m<10;m++)
          {

             for(int x=0;x<10;x++)
             for(int y=0;y<10;y++)
             {
            if((pre_molap[i][j][k].branch_list[m])==(location_branch[x][y].branch_id))
            {
              // output_join_loaction<<pre_molap[i][j][k].branch_list[m]<<"              "<<mapping_location_name(x)<<"            "<<mapping_branch_name(y)<<"   "<<endl;
               for(int pn=0;pn<10;pn++)
               {
                   for(int mn=0;mn<10;mn++)
                   {
                      if(pre_molap[i][j][k].product_information[m][pn][mn]==0)
                      {
                          break;
                      }
                      else{
                        output_join_loaction<<pre_molap[i][j][k].branch_list[m]<<"              "<<mapping_location_name(x)<<"            "<<mapping_branch_name(y)<<"          "<<mapping_product_name(pn)<<"          "<<mapping_model_name(mn)<<"         "<<pre_molap[i][j][k].product_information[m][pn][mn]<<"   "<<coun<<endl;
                        coun++;
                      }
                   }
               }
            }
            }

          }
        }

}
void join_for_shipping_molap()
{
    ofstream output_join_shipping("shipping_molap_join.txt");
    output_join_shipping<<"Product_id:"<<"  "<<"Product_name:"<<"  "<<"Product_model:"<<"  "<<"From:"<<"   "<<"To:"<<"  "<<"Quantity:"<<" "<<"Month:"<<"   "<<"Week:"<<"  "<<"Year:"<<endl;
  for(int i=0;i<10;i++)
  {
      for(int j=0;j<10;j++)
      {
          for(int k=0;k<10;k++)
          {
              for(int index=0;index<10;index++)
              {
                 //product_name extract from product_model
                 int pn_index=0;
                 int pm_index=0;
                 int from_location_index=0;
                 int to_location_index=0;
                 for(int pn=0;pn<10;pn++)
                 {
                     for(int pm=0;pm<10;pm++)
                     {
                         if(shipping[i][j][k].product_id[index]==product_model[pn][pm].product_id)
                         {
                             pn_index=pn;
                             pm_index=pm;

                         }
                         if(shipping[i][j][k].from_location[index]==location_branch[pn][pm].branch_id)
                         {
                             from_location_index=pn;
                         }
                         if(shipping[i][j][k].to_location[index]=location_branch[pn][pm].branch_id)
                         {
                            to_location_index=pn;
                         }
                     }
                 }
             output_join_shipping<<shipping[i][j][k].product_id[index]<<"       "<<mapping_product_name(pn_index)<<"            "<<mapping_model_name(pm_index)<<"            "<<mapping_location_name(from_location_index)<<"      "<<mapping_location_name(to_location_index)<<"   "<<shipping[i][j][k].units_shipped[index]<<"      "<<mapping_month_name(j)<<"   "<<mapping_week_name(k)<<"   "<<mapping_year_name(i)<<endl;

              }
          }
      }
  }
}

void join_for_production_molap()
{
    ofstream join_output_pro_molap("join for production molap.txt");
    join_output_pro_molap<<"Product_id:"<<" "<<"Product_name:"<<" "<<"Product_model:"<<" "<<"Quantity:"<<" "<<"Month:"<<" "<<"Year:"<<"            "<<"Total_cost:"<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<1;k++)
            {
              for(int index=0;index<10;index++)
              {
                 for(int pn=0;pn<10;pn++)
                 {
                     for(int pm=0;pm<10;pm++)
                     {
                         if(pre_production_molap[i][j][k].product_id[index]==product_model[pn][pm].product_id)
                         {
                             join_output_pro_molap<<pre_production_molap[i][j][k].product_id[index]<<"          "<<mapping_product_name(pn)<<"         "<<mapping_model_name(pm)<<"              "<<pre_production_molap[i][j][k].product_units[index]<<"      "<<mapping_month_name(j)<<"    "<<mapping_year_name(i)<<"             "<<pre_production_molap[i][j][k].production_cost[index]<<endl;
                         }
                     }
                 }
              }
            }
        }
    }
}
void join_between_selling_and_production_molap()
{
  ofstream output_join("output_join_btw_selling_production_molap.txt");
  output_join<<"Product_id:"<<" "<<"Product_name:"<<" "<<"Model_name:"<<"Selling Quantity:"<<" "<<"Production_units:"<<"   "<<"Production_cost:"<<"   "<<"Month:"<<"    "<<"Week:"<<"   "<<"Year:"<<endl;
  for(int i=0;i<10;i++)
  {
      for(int j=0;j<10;j++)
      {
          for(int k=0;k<10;k++)
          {
              for(int index=0;index<10;index++)
              {
                  for(int pr_index=0;pr_index<10;pr_index++)
                  {
                 if(pre_molap[i][j][k].model_list[index]==pre_production_molap[i][j][0].product_id[pr_index])
                 {
                     for(int pn=0;pn<10;pn++)
                     {
                         for(int pm=0;pm<10;pm++)
                         {
                           if(pre_molap[i][j][k].model_list[index]==product_model[pn][pm].product_id)
                           {
                              output_join<<pre_molap[i][j][k].model_list[index]<<"           "<<mapping_product_name(pn)<<"           "<<mapping_model_name(pm)<<"     "<<pre_molap[i][j][k].quantity[index]<<"              "<<pre_production_molap[i][j][0].product_units[pr_index]<<"                "<<pre_production_molap[i][j][0].production_cost[pr_index]<<"        "<<mapping_month_name(j)<<"          "<<mapping_week_name(k)<<"    "<<mapping_year_name(i)<<endl;
                           }
                         }
                     }
                 }
                  }
              }
          }
      }
  }

}
void join_between_selling_and_shipping_molap()
{
    ofstream output_join("join_output_selling_and_shipping_location.txt");
    output_join<<"Product_id:"<<" "<<"Product_name:"<<" "<<"Model_name:"<<"Selling Quantity:"<<" "<<"Shipping_from:"<<"   "<<"Shipping_to:"<<"  "<<"Shipping_units"<<" "<<"Shipping_cost:"<<"   "<<"Month:"<<"    "<<"Week:"<<"   "<<"Year:"<<endl;
    for(int i=0;i<10;i++)
          {
              for(int j=0;j<10;j++)
              {
                  for(int k=0;k<10;k++)
                  {
                    for(int index=0;index<10;index++)
                    {
                        for(int s_index=0;s_index<10;s_index++)
                         {

                       if(pre_molap[i][j][k].model_list[index]==shipping[i][j][k].product_id[s_index])
                       {

                           int p_name,p_model,f_l_name,t_l_name;
                         for(int pn=0;pn<10;pn++)
                         {
                             for(int pm=0;pm<10;pm++)
                             {
                                if(pre_molap[i][j][k].model_list[index]==product_model[pn][pm].product_id)
                                {
                                    p_name=pn;
                                    p_model=pm;
                                   // output_join<<pre_molap[i][j][k].model_list[index]<<" "<<mapping_product_name(pn)<<" "<<mapping_model_name(pm)<<" "<<pre_molap[i][j][k].quantity[index]<<" "<<
                                }
                                if(shipping[i][j][k].from_location[index]==location_branch[pn][pm].branch_id)
                                {
                                  f_l_name=pn;
                                }
                                if(shipping[i][j][k].to_location[index]==location_branch[pn][pm].branch_id)
                                {
                                   t_l_name=pn;
                                }
                             }
                         }

                          output_join<<pre_molap[i][j][k].model_list[index]<<"       "<<mapping_product_name(p_name)<<"       "<<mapping_model_name(p_model)<<"       "<<pre_molap[i][j][k].quantity[index]<<"        "<<mapping_location_name(f_l_name)<<"       "<<mapping_location_name(t_l_name)<<"          "<<shipping[i][j][k].units_shipped[s_index]<<"           "<<shipping[i][j][k].cost_per_shipped[s_index]<<endl;
                       }
                    }
                    }
                  }
              }
          }
}
void molap_creation()
{
  for(int i=0;i<10;i++)
  {
      int location_total_product[10][10]={0};
      //int total_income[10][10]={0};
     // int location[10]={0};
      int location_index;
    for(int j=0;j<10;j++)
    {
        for(int k=0;k<10;k++)
        {
        // int total_product[10]={0};
          for(int bi=0;bi<10;bi++)
          {
              for(int location=0;location<10;location++)
              {
                  for(int branch=0;branch<10;branch++)
                  {
                     if((pre_molap[i][j][k].branch_list[bi])==(location_branch[location][branch].branch_id))
                     {
                       location_index=location;
                     }
                  }
              }
              for(int pn=0;pn<10;pn++)
              {
                  for(int pm=0;pm<10;pm++)
                  {
                   location_total_product[location_index][pn]=location_total_product[location_index][pn]+pre_molap[i][j][k].product_information[bi][pn][pm];
                  }
              }
          }
        }
    }
    //assign summarize value to molap1
    // i represents Year
    for(int pro=0;pro<10;pro++)
    {
       for(int loc=0;loc<10;loc++)
       {
          molap1[pro][loc][i].quantity=location_total_product[loc][pro];
       }
    }
  }

  //total revenue calculation

   for(int i=0;i<10;i++)
  {
     // int location_total_product[10][10]={0};
      int total_income[10][10]={0};
      int location_index;
    for(int j=0;j<10;j++)
    {
        for(int k=0;k<10;k++)
        {

          for(int bi=0;bi<10;bi++)
          {
              for(int location=0;location<10;location++)
              {
                  for(int branch=0;branch<10;branch++)
                  {
                     if((pre_molap[i][j][k].branch_list[bi])==(location_branch[location][branch].branch_id))
                     {
                       location_index=location;
                     }
                  }
              }
              for(int pn=0;pn<10;pn++)
              {
                  for(int pm=0;pm<10;pm++)
                  {
                   total_income[location_index][pn]=total_income[location_index][pn]+(pre_molap[i][j][k].product_information[bi][pn][pm]*product_model[pn][pm].price);
                  }
              }
          }
        }
    }
    //assign summarize value to molap1
    // i represents Year
    for(int pro=0;pro<10;pro++)
    {
       for(int loc=0;loc<10;loc++)
       {
          molap1[pro][loc][i].total_revenue=total_income[loc][pro];
       }
    }
  }

}
void shipping_molap_creation()
{
    int location_index=0;
    int product_name_index=0;
   // int location_product[10][10]={0};
    for(int i=0;i<10;i++)
    {
     int location_product_quantity[10][10]={0};
      int location_product_cost[10][10]={0};
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int index=0;index<10;index++)
                {
                     location_index=0;
                     product_name_index=0;
                     for(int pn=0;pn<10;pn++)
                    {
                       for(int pm=0;pm<10;pm++)
                       {
                           if(shipping[i][j][k].product_id[index]==product_model[pn][pm].product_id)
                           {
                               product_name_index=pn;
                           }
                           if(shipping[i][j][k].to_location[index]==location_branch[pn][pm].branch_id)
                           {
                               location_index=pn;
                           }
                       }

                    }
                    location_product_quantity[location_index][product_name_index]=location_product_quantity[location_index][product_name_index]+shipping[i][j][k].units_shipped[index];
                    location_product_cost[location_index][product_name_index]=location_product_cost[location_index][product_name_index]+shipping[i][j][k].cost_per_shipped[index];

                }
            }
        }

     for(int pro=0;pro<10;pro++)
    {
       for(int loc=0;loc<10;loc++)
       {
          shipping_molap[pro][loc][i].shipping_quantity=location_product_quantity[loc][pro];
          shipping_molap[pro][loc][i].total_shipping_cost=location_product_cost[loc][pro];
       }
    }
    }
}

void production_molap_creation()
{
   for(int i=0;i<10;i++)
   {
       int product_quantity[10][10]={0};
       int product_cost[10][10]={0};
       for(int j=0;j<10;j++)
       {
           //k represent country
           for(int k=0;k<10;k++)
           {
               for(int index=0;index<10;index++)
               {
            int product_name_index=0;
            int cost=0;
             for(int pn=0;pn<10;pn++)
             {
                 for(int pm=0;pm<10;pm++)
                 {
                    if(pre_production_molap[i][j][k].product_id[index]==product_model[pn][pm].product_id)
                    {
                       product_name_index=pn;

                    }
                 }
             }

             product_quantity[product_name_index][k]=product_quantity[product_name_index][k]+pre_production_molap[i][j][k].product_units[index];
             product_cost[product_name_index][k]=product_cost[product_name_index][k]+pre_production_molap[i][j][k].production_cost[index];
               }
           }
       }
       // assign product quantity to production molap
       for(int prod_name=0;prod_name<10;prod_name++)
       {
           for(int country=0;country<10;country++)
           {
               production_molap[prod_name][country][i].total_quantity=product_quantity[prod_name][country];
               production_molap[prod_name][country][i].total_production_cost=product_cost[prod_name][country];
           }
       }
   }
}
void fact_table_creation()
{
    int index=0;
    // First section
   for(int i=0;i<10;i++)
   {
       for(int j=0;j<10;j++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int k=0;k<10;k++)
           {
             product_quantity=product_quantity+molap1[i][j][k].quantity;
             total_dollar=total_dollar+molap1[i][j][k].total_revenue;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }
   }
   //Second section
     for(int i=0;i<10;i++)
   {
       for(int k=0;k<10;k++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int j=0;j<10;j++)
           {
             product_quantity=product_quantity+molap1[i][j][k].quantity;
             total_dollar=total_dollar+molap1[i][j][k].total_revenue;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }
   }
   //Third section
     for(int j=0;j<10;j++)
   {
       for(int k=0;k<10;k++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int i=0;i<10;i++)
           {
             product_quantity=product_quantity+molap1[i][j][k].quantity;
             total_dollar=total_dollar+molap1[i][j][k].total_revenue;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }

  }
  //Fact_table_for shipping

     for(int i=0;i<10;i++)
   {
       for(int j=0;j<10;j++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int k=0;k<10;k++)
           {
             product_quantity=product_quantity+shipping_molap[i][j][k].shipping_quantity;
             total_dollar=total_dollar+shipping_molap[i][j][k].total_shipping_cost;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }
   }
   //Second section
     for(int i=0;i<10;i++)
   {
       for(int k=0;k<10;k++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int j=0;j<10;j++)
           {
             product_quantity=product_quantity+shipping_molap[i][j][k].shipping_quantity;
             total_dollar=total_dollar+shipping_molap[i][j][k].total_shipping_cost;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }
   }
   //Third section
     for(int j=0;j<10;j++)
   {
       for(int k=0;k<10;k++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int i=0;i<10;i++)
           {
             product_quantity=product_quantity+shipping_molap[i][j][k].shipping_quantity;
             total_dollar=total_dollar+shipping_molap[i][j][k].total_shipping_cost;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }

  }

  //fact table creation for production molap

      for(int i=0;i<10;i++)
   {
       for(int j=0;j<10;j++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int k=0;k<10;k++)
           {
             product_quantity=product_quantity+production_molap[i][j][k].total_quantity;
             total_dollar=total_dollar+production_molap[i][j][k].total_production_cost;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }
   }


  //second section
        for(int i=0;i<10;i++)
   {
       for(int k=0;k<10;k++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int j=0;j<10;j++)
           {
             product_quantity=product_quantity+production_molap[i][j][k].total_quantity;
             total_dollar=total_dollar+production_molap[i][j][k].total_production_cost;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }
   }
  //third section

        for(int j=0;j<10;j++)
   {
       for(int k=0;k<10;k++)
       {
          int product_quantity=0;
          int total_dollar=0;
           for(int i=0;i<10;i++)
           {
             product_quantity=product_quantity+production_molap[i][j][k].total_quantity;
             total_dollar=total_dollar+production_molap[i][j][k].total_production_cost;
           }
           fact_table[index].final_quantity=product_quantity;
           fact_table[index].final_revenue=total_dollar;
           index++;
       }
   }

  //fact_table output
  ofstream fact_table_output("fact_table_output.txt");
 for(int i=0;i<1000;i++)
 {
    fact_table_output<< fact_table[i].final_quantity<<"  "<<fact_table[i].final_revenue<<endl;
 }
}
int main()
{
    int product_model_matrix[10][10]={0};
    ofstream output_price("product_model_price.txt");
    for(int i=0;i<10;i++)
    {
    for(int j=0;j<10;j++)
    {
     output_price<<rand()%1000<<"  ";
    }
    output_price<<endl;
    }
    int temp=0;
    ofstream output_product_id("product_model_id.txt");
    for(int i=0;i<10;i++)
    {
    for(int j=0;j<10;j++)
    { temp=((rand()%100)+(rand()%100)+(j+1));
      output_product_id<<temp<<"  ";
      product_model_matrix[i][j]=temp;
    }
    output_product_id<<endl;
    }
   /* //code for product_model matrix visualization
      ofstream out_product_id("product_model_id_matrix.txt");
      out_product_id<<"          ";
      for(int c=0;c<10;c++)
      out_product_id<<model_name[c]<<"             ";
      out_product_id<<endl;
    for(int i=0;i<10;i++)
    {
        out_product_id<<product_name[i]<<"        ";
    for(int j=0;j<10;j++)
    {
     out_product_id<<product_model_matrix[i][j]<<"            ";
    }
    out_product_id<<endl;
    }
    */


   ifstream input_prduct_price("product_model_price.txt");
    for (int i=0 ; i<10 ; i++)
    for (int j=0 ; j<10 ; j++)
    {

        input_prduct_price>>product_model[i][j].price ;

    }
    ifstream input_prduct_id("product_model_id.txt");
    for (int i=0 ; i<10 ; i++)
    {

    for (int j=0 ; j<10 ; j++)
    {

        input_prduct_id>>product_model[i][j].product_id ;

    }
    }
   ofstream output_location_branch("location_branch_id.txt");
        for (int i=0 ; i<10 ; i++)
        {
            int coun=1;
        for (int j=0 ; j<10 ; j++)
      {

        output_location_branch<<(((rand()+coun)%100)+(rand()%100)+(j+1))<<"  ";
        coun++;
        //output_location_branch<<j<<"  ";

      }
      output_location_branch<<endl;
        }
      ifstream input_location_branch("location_branch_id.txt");
        for (int i=0 ; i<10 ; i++)
        for (int j=0 ; j<10 ; j++)
      {

        input_location_branch>>location_branch[i][j].branch_id;

      }

      for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
      {
       // pre_molap[i][j][k].quantity=(100+rand()%100);
         //pre_molap[i][j][k].quantity=0;
          for(int m=0;m<10;m++)
          {
             int temp1=rand()%10;
             int temp2=rand()%10;
             pre_molap[i][j][k].quantity[m]=temp1;
             pre_molap[i][j][k].model_list[m]=product_model[temp1][temp2].product_id;
             int temp3=rand()%10;
             int temp4=rand()%10;
             pre_molap[i][j][k].branch_list[m]=location_branch[temp3][temp4].branch_id;
          }

      }

      //product information measurement
       for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
            {
               for(int bi=0;bi<10;bi++)
                for(int pn=0;pn<10;pn++)
                  for(int mn=0;mn<10;mn++)
                  {
                    pre_molap[i][j][k].product_information[bi][pn][mn]=rand()%3;
                  }
            }

      //shipping pre_molap initialize

      for(int i=0;i<10;i++)
      {
          for(int j=0;j<10;j++)
          {
              for(int k=0;k<10;k++)
              {
                  int coun=1;
                  for(int loc=0;loc<10;loc++)
                  {

                          int temp1=(rand()+coun)%10;
                          int temp2=rand()%10;
                          coun++;
                          shipping[i][j][k].product_id[loc]=product_model[temp1][temp2].product_id;
                          temp1=(rand()+coun)%10;
                          temp2=rand()%10;
                          coun++;
                          shipping[i][j][k].from_location[loc]=location_branch[temp1][temp2].branch_id;
                          temp1=rand()%10;
                          temp2=(rand()+coun)%10;
                          shipping[i][j][k].to_location[loc]=location_branch[temp1][temp2].branch_id;
                          shipping[i][j][k].units_shipped[loc]=20+rand()%100;
                          shipping[i][j][k].cost_per_shipped[loc]=rand()%500;

                  }
              }
          }
      }
      //production_cost initialize
      for(int i=0;i<10;i++)
      {
          for(int j=0;j<10;j++)
          {

              production_cost[i][j].product_id=product_model[i][j].product_id;
              production_cost[i][j].production_cost=1000+rand()%5000;
          }
      }

       //available molap initialize
       // i represent product
      for(int i=0;i<10;i++)
      {
          //j represent model
          for(int j=0;j<10;j++)
          {   //k represent month
              for(int k=0;k<10;k++)
              {
                 for(int index=0;index<10;index++)
                 {
                     int coun=1;
                   int temp1;
                   int temp2;
                    temp1=(coun+rand())%10;
                    coun++;
                    temp2=(coun+rand())%10;
                    available[i][j][k].available_product_id[index]=product_model[temp1][temp2].product_id;
                    available[i][j][k].available_product_units[index]=rand()%1000;
                    coun++;
                    temp1=(coun+rand())%10;
                    coun++;
                    temp2=(coun+rand())%10;

                    available[i][j][k].required_product_id[index]=product_model[temp1][temp2].product_id;
                    available[i][j][k].required_product_units[index]=rand()%500;
                 }
              }
          }
      }

       //pre_production_molap initialization
       for(int i=0;i<10;i++)
       {
           for(int j=0;j<10;j++)
           {
               //k represent county.
               for(int k=0;k<1;k++)
               {
                   for(int index=0;index<10;index++)
                   {
                       int coun=1;
                       int temp1=(rand()+coun)%10;
                       coun++;
                       int temp2=(rand()+coun)%10;
                       pre_production_molap[i][j][k].product_id[index]=product_model[temp1][temp2].product_id;
                       pre_production_molap[i][j][k].product_units[index]=5+rand()%20;
                       for(int pn=0;pn<10;pn++)
                       {
                           for(int pm=0;pm<10;pm++)
                           {
                               if(pre_production_molap[i][j][k].product_id[index]==production_cost[pn][pm].product_id)
                               {

                                pre_production_molap[i][j][k].production_cost[index]=(pre_production_molap[i][j][k].product_units[index]*production_cost[pn][pm].production_cost);
                               }
                           }
                       }


                   }
               }
           }
       }


      //join_with_location();
      //join2();
      //join_for_shipping_molap();
      join_between_selling_and_production_molap();
      join_between_selling_and_shipping_molap();
      molap_creation();
      shipping_molap_creation();
      //join_for_production_molap();
      //fact_table_creation();
}
