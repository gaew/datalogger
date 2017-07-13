
<!DOCTYPE html>
<html>
<title>HSS1 datalogger</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/lib/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Lato">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
body {font-family: "Lato", sans-serif}
.mySlides {display: none}
</style>
<body>
<form action="view.php" method="post">
    <div class="w3-container">
        <p><label>โมเดลทดลองการทำงานเครื่องวัดและแจ้งเตือนอุณหภูมิตู้เย็นแช่ยา และ blood bank ของสำนักสนับสนุนบริการสุขภาพเขต 1 จังหวัดเชียงใหม่</label></p>
       	<p><label>(model S/N 01)</label></p>


<p><label>รายงานล่าสุด</label></p>

<iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/302081/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>


<iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/302081/charts/2?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>

        <p><label>ดูรายงานตามช่วงเวลา</label></p>
       
    
    	<p><input type="date" name="dateFrom" value="<?php $d=strtotime("-1 weeks");
		echo date("Y-m-d", $d); ?>" /></p>   

    

    	<p><input type="date" name="dateTo" value="<?php $d=strtotime("+1 day");
		echo date("Y-m-d", $d); ?>" /></p>
    

    	<input type="submit" name="submit" value="ดูรายงาน" button class="w3-btn-block w3-teal w3-padding-12 w3-section w3-right"></button>
		
		<p><label>รายชื่ออีเมลที่มีการส่งรายงานประจำวันไปให้ (เพิ่มอีเมลติดต่อผู้ดูแลระบบ)</label></p>
		<p><label>gaewgan.y@gmail.com</label></p>
 	</div>

</body>
</html>