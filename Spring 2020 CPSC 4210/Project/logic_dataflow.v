module logic(out, a, b, select);
 output reg [31:0] out;
 input [31:0] a, b;
 input [1:0] select;
 
 always@*
 begin
	if(select == 0)
		out = a&b;
	else if(select == 1)
		out = a|b;
	else if(select == 2)
		out =a^b;
	else if(select == 3)
		out = ~(a|b);
end	
endmodule

module stimulus;
wire [31:0] z;
reg [31:0] x, y;
reg [1:0] select;
logic logic_func(z, x, y, select);

initial
begin
	$monitor($time, "x = %b, y = %b, select = %b, ----- z = %b\n", x, y, select, z);
end

initial
begin
	x = 32'b00000000000000000000000000000110; y = 32'b00000000000000000000000000001100; select = 2'b00;
	#2 x = 32'b00000000000000000000000000000110; y = 32'b00000000000000000000000000001100; select = 2'b01;
	#2 x = 32'b00000000000000000000000000000110; y = 32'b00000000000000000000000000001100; select = 2'b10;
	#2 x = 32'b00000000000000000000000000000110; y = 32'b00000000000000000000000000001100; select = 2'b11;
end
endmodule