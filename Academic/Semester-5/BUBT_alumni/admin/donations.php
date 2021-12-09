<?php include('db_connect.php');?>

<div class="container-fluid">
<style>
	input[type=checkbox]
{
  /* Double-sized Checkboxes */
  -ms-transform: scale(1.5); /* IE */
  -moz-transform: scale(1.5); /* FF */
  -webkit-transform: scale(1.5); /* Safari and Chrome */
  -o-transform: scale(1.5); /* Opera */
  transform: scale(1.5);
  padding: 10px;
}
</style>
	<div class="col-lg-12">
		<div class="row mb-4 mt-4">
			<div class="col-md-12">
				
			</div>
		</div>
		<div class="row">
			<!-- FORM Panel -->

			<!-- Table Panel -->
			<div class="col-md-12">
				<div class="card">
					<div class="card-header">
						<b>Donations List</b>
						<span class="">

							<button class="btn btn-primary btn-block btn-sm col-sm-2 float-right" type="button" id="new_donation">
					<i class="fa fa-plus"></i> New</button>
				</span>
					</div>
					<div class="card-body">
						
						<table class="table table-bordered table-condensed table-hover">
							<colgroup>
								<col width="5%">
								<col width="20%">
								<col width="30%">
								<col width="20%">
								<col width="10%">
								<col width="15%">
							</colgroup>
							<thead>
								<tr>
									<th class="text-center">#</th>
									<th class="">Phone Number</th>
									<th class="">Message</th>
									<th class="">Donated By</th>
									<th class="">Amount</th>
                                    <th class="">Status</th>
									<th class="text-center">Action</th>
								</tr>
							</thead>
							<tbody>
								<?php 
								$i = 1;
								$Forum =  $conn->query("SELECT f.*,u.name from donations f inner join users u on u.id = f.user_id order by f.id desc");
								while($row=$Forum->fetch_assoc()):
									 $trans = get_html_translation_table(HTML_ENTITIES,ENT_QUOTES);
								        unset($trans["\""], $trans["<"], $trans[">"], $trans["<h2"]);
								        $desc = strtr(html_entity_decode($row['message']),$trans);
								        $desc=str_replace(array("<li>","</li>"), array("",","), $desc);
								    
								?>
								<tr>
									
									<td class="text-center"><?php echo $i++ ?></td>
									<td class="">
										 <p><b><?php echo ucwords($row['number']) ?></b></p>
										 
									</td>
									<td class="">
										 <p class="truncate"><b><?php echo $desc ?></b></p>
										 
									</td>
									<td class="">
										 <p><b><?php echo ucwords($row['name']) ?></b></p>
										 
									</td>
                                    	<td class="">
										 <p><b><?php echo ucwords($row['amount']) ?> BDT</b></p>
										 
									</td>
                                    <td class="text-center">
										<?php if($row['status'] == 1): ?>
											<span class="badge badge-primary">Verified</span>
										<?php else: ?>
											<span class="badge badge-secondary">Not Verified</span>
										<?php endif; ?>

									</td>
									
									<td class="text-center">
										<button class="btn btn-sm btn-outline-primary view_donations" type="button" data-id="<?php echo $row['id'] ?>" >View</button>
                                        <button class="btn btn-sm btn-outline-danger delete_donation" type="button" data-id="<?php echo $row['id'] ?>">Delete</button>
									</td>
								</tr>
								<?php endwhile; ?>
							</tbody>
						</table>
					</div>
				</div>
			</div>
			<!-- Table Panel -->
		</div>
	</div>	

</div>
<style>
	
	td{
		vertical-align: middle !important;
	}
	td p{
		margin: unset
	}
	img{
		max-width:100px;
		max-height: :150px;
	}
</style>
<script>
	$(document).ready(function(){
		$('table').dataTable()
	})
	$('#new_donation').click(function(){
		uni_modal("New Donation","manage_donations.php",'mid-large')
	})
	
	$('.view_donations').click(function(){
		uni_modal("Donation Verify","view_donations.php?id="+$(this).attr('data-id'),'mid-large')
		
	})
	$('.delete_donation').click(function(){
		_conf("Are you sure to delete this alumni?","delete_alumni",[$(this).attr('data-id')])
	})
	
	function delete_alumni($id){
		start_load()
		$.ajax({
			url:'ajax.php?action=delete_donation',
			method:'POST',
			data:{id:$id},
			success:function(resp){
				if(resp==1){
					alert_toast("Data successfully deleted",'success')
					setTimeout(function(){
						location.reload()
					},1500)

				}
			}
		})
	}
</script>