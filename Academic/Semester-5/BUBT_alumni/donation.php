<?php 
include 'admin/db_connect.php'; 
?>
<style>
#portfolio .img-fluid{
    width: calc(100%);
    height: 30vh;
    z-index: -1;
    position: relative;
    padding: 1em;
}
.gallery-list{
cursor: pointer;
border: unset;
flex-direction: inherit;
}
.gallery-img,.gallery-list .card-body {
    width: calc(50%)
}
.gallery-img img{
    border-radius: 5px;
    min-height: 50vh;
    max-width: calc(100%);
}
span.hightlight{
    background: yellow;
}
.carousel,.carousel-inner,.carousel-item{
   min-height: calc(100%)
}
header.masthead,header.masthead:before {
        min-height: 50vh !important;
        height: 50vh !important
    }
.row-items{
    position: relative;
}
.masthead{
        min-height: 23vh !important;
        height: 23vh !important;
    }
     .masthead:before{
        min-height: 23vh !important;
        height: 23vh !important;
    }

</style>
<header class="masthead">
    <div class="container-fluid h-100">
        <div class="row h-100 align-items-center justify-content-center text-center">
            <div class="col-lg-8 align-self-end mb-4 page-title">
                <h3 class="text-white">Donation List</h3>
                <hr class="divider my-4" />
            <div class="row col-md-12 mb-2 p-2 justify-content-center">
                    <button class="btn btn-primary btn-block col-sm-4" type="button" id="new_donation"><i style="font-size:30px;" class="fa fa-donate"></i> Donate Now (Anyone can Donate)</button>
            </div>   
            </div>
            
        </div>
    </div>
</header>
<div class="container mt-3 pt-2">
   <?php
    $total = $conn->query("SELECT SUM(amount) AS totalsum FROM donations where status = 1");
    $row = mysqli_fetch_assoc($total); 
    $sum = $row['totalsum'];
        $count_donators=0;
        $count_donators = $conn->query("SELECT * FROM donations where status = 1")->num_rows;
    ?>
    <div class="card forum-list">
        <div class="card-body">
            <div class="row  align-items-center justify-content-center text-center h-100">
                <div class="">
            <h2>Total Donators: <b><span style="color:red;"><?php echo $count_donators ?></span></b></h2>
                   <h2>Total Donation:<b><span style="color:red;"><?php echo $sum ?></span></b>  BDT</h2>
            
                </div>
            </div>
            

        </div>
    </div>
    <br>
    
</div>
    
</div>


<script>
    // $('.card.gallery-list').click(function(){
    //     location.href = "index.php?page=view_gallery&id="+$(this).attr('data-id')
    // })
    $('#new_donation').click(function(){
        uni_modal("New Donation (Bkash or Nagad)","manage_donation.php",'mid-large')
    })

    $('#filter').keypress(function(e){
    if(e.which == 13)
        $('#search').trigger('click')
   })
    $('#search').click(function(){
        var txt = $('#filter').val()
        start_load()
        if(txt == ''){
        $('.forum-list').show()
        end_load()
        return false;
        }
        $('.forum-list').each(function(){
            var content = "";
            $(this).find(".filter-txt").each(function(){
                content += ' '+$(this).text()
            })
            if((content.toLowerCase()).includes(txt.toLowerCase()) == true){
                $(this).toggle(true)
            }else{
                $(this).toggle(false)
            }
        })
        end_load()
    })

</script>