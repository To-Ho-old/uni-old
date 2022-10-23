module SR_Latch ( s ,r ,enable ,reset ,q ,qb );

output q ;
reg q ;
output qb ;
reg qb ;

input s ;
wire s ;
input r ;
wire r ;
input enable ;
wire enable ;
input reset ;
wire reset ;

always @ (enable or s or r or reset) begin
 if (reset) begin
  q = 0;
  qb = 1;   
 end else if (enable) begin
  if (s!=r) begin
   q = s;
   qb = r;
  end else if (s==1 && r==1) begin
   q = 1'bZ;
   qb = 1'bZ;
  end
 end
end

endmodule