var mid=25;
var high=50;
var low=1;
var current=13;
var found=-1;
if(current<mid)
{
    mid=(current-low)/2;
}else if(current>mid)
{
    mid=(current-+high)/2;
}else{
    found=current;
}
var monthNum=3;
var monthName;
switch(monthNum)
{
    case "1":
        monthName="january";
        break;
    case "2":
        monthName="february";
        break;
    case "3":
        monthName="march";
        break;
    case "4":
        monthName="april";
        break;
    case "5":
        monthName="may";
        break;
    case "6":
        monthName="june";
        break;
    case "7":
        monthName="july";
        break;
    case "8":
        monthName="auguest";
        break;
    case "9":
        monthName = "September";
        break;
    case "10":
        monthName = "October";
        break;
    case "11":
        monthName = "November";
        break;
    case "12":
        monthName = "December";
        break;
    default:
        console.log("Bad input");
}