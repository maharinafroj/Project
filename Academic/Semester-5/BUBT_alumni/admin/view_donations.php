<?php include 'db_connect.php' ?>
<?php
if(isset($_GET['id'])){
$qry = $conn->query("SELECT f.*,u.name from donations f inner join users u on u.id = f.user_id where f.id= ".$_GET['id']);
foreach($qry->fetch_array() as $k => $val){
	$$k=$val;
}
}
?>
<style type="text/css">
	
	.avatar {
	    display: flex;
	    border-radius: 100%;
	    width: 100px;
	    height: 100px;
	    align-items: center;
	    justify-content: center;
	    border: 3px solid;
	    padding: 5px;
	}
	.avatar img {
	    max-width: calc(100%);
	    max-height: calc(100%);
	    border-radius: 100%;
	}
	p{
		margin:unset;
	}
	#uni_modal .modal-footer{
		display: none
	}
	#uni_modal .modal-footer.display{
		display: block
	}
</style>
<div class="container-field">
	<div class="col-lg-12">
	
		<div class="row">
			<div class="col-md-6">
				<p>Payment Type: <b><?php echo $ptype ?></b></p>
				<p>Phone Number: <b><?php echo $number ?></b></p>
				<p>Amount: <b><?php echo $amount ?> BDT</b></p>
				<p>Transaction ID: <b><?php echo $trxid ?></b></p>
			</div>
			<div class="col-md-6">
				<p>Gender: <b><?php echo $name ?></b></p>
				<p>Account Status: <b><?php echo $status == 1 ? '<span class="badge badge-primary">Verified</span>' : '<span class="badge badge-secondary">Unverified</span>' ?></b></p>
			</div>
		</div>
	</div>
</div>
<div class="modal-footer display">
	<div class="row">
		<div class="col-lg-12">
			<button class="btn float-right btn-secondary" type="button" data-dismiss="modal">Close</button>
			<?php if($status == 1): ?>
			<button class="btn float-right btn-primary update mr-2" data-status = '0' type="button" data-dismiss="modal">Unverify Account</button>
			<?php else: ?>
				<button class="btn float-right btn-primary update mr-2" data-status = '1' type="button" data-dismiss="modal">Verify Account</button>
			<?php endif; ?>
		</div>
	</div>
</div>
<script>
	$('.update').click(function(){
		start_load()
		$.ajax({
			url:'ajax.php?action=update_donation',
			method:"POST",
			data:{id:<?php echo $id ?>,status:$(this).attr('data-status')},
			success:function(resp){
				if(resp == 1){
					alert_toast("Donation status successfully updated.")
					setTimeout(function(){
						location.reload()
					},1000)
				}
			}
		})
	})
</script>