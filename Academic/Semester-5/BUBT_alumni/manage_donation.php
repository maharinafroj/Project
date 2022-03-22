<?php include 'admin/db_connect.php' ?>
<?php
if(isset($_GET['id'])){
	$qry = $conn->query("SELECT * FROM donations where id=".$_GET['id'])->fetch_array();
	foreach($qry as $k =>$v){
		$$k = $v;
	}
}

?>
<div class="container-fluid">
	<form action="" id="manage-donation">
				<input type="hidden" name="id" value="<?php echo isset($_GET['id']) ? $_GET['id']:'' ?>" class="form-control">

        <div class="row form-group">
            <div class="col-md-6">
                <label for="" class="control-label">Payment Type</label>
            <select class="custom-select" name="ptype" required>
               <option value="none">Please Select</option>
                <option value="bkash">Bkash</option>
                <option value="nagad">Nagad</option>
                </select>
            </div>
        <div class="row form-group">
			<div class="col-md-12">
				<label class="control-label">Phone Number used to pay</label>
				<input type="text" name="number" class="form-control" value="<?php echo isset($number) ? $number:'' ?>">
			</div>
		</div>
        <div class="row form-group">
			<div class="col-md-8">
				<label class="control-label">Amount to Donate (BDT)</label>
				<input type="number" name="amount" class="form-control" value="<?php echo isset($amount) ? $amount:'' ?>">
			</div>
		</div>
        <div class="row form-group">
			<div class="col-md-12">
				<label class="control-label">Transaction Id</label>
				<input type="text" name="trxid" class="form-control" value="<?php echo isset($trxid) ? $trxid:'' ?>">
			</div>
		</div>
		<div class="row form-group">
			<div class="col-md-12">
				<label class="control-label">Message</label>
				<textarea name="message" class="text-jqte"><?php echo isset($message) ? $message : '' ?></textarea>
			</div>
		</div>
	</form>
</div>

<script>
	$('.text-jqte').jqte();
	$('#manage-donation').submit(function(e){
		e.preventDefault()
		start_load()
		$.ajax({
			url:'admin/ajax.php?action=save_donation',
			method:'POST',
			data:$(this).serialize(),
			success:function(resp){
                console.log(resp)
				if(resp == 1){
					alert_toast("Data successfully saved.",'success')
					setTimeout(function(){
						location.reload()
					},1000)
				}
			}
		})
	})
</script>