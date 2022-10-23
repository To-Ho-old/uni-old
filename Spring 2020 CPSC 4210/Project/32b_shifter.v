module shifter(out, in, shift, select);
output reg [31:0] out;
input [31:0] in;
input [4:0] shift;
input select;

always@*
begin
if(~select)
	out = in<<shift;
else if(select)
	out = in>>shift;
end
endmodule

module stimulus;
reg [31:0] x;
reg [4:0] shift_amount;
reg select;
wire [31:0] OUT;

shifter myshifter(OUT, x, shift_amount, select);

initial
	begin
		$monitor($time, "x = %b, shift_amount = %b|%d, select = %b, output = %b\n", x, shift_amount, shift_amount, select, OUT);
		//$monitor($time, "x = %d, shift_amount = %d, select = %b, output = %d\n", x, shift_amount, select, OUT);
	end
initial
	begin
		x = 32'd0; shift_amount = 5'd0; select = 1'b0;
		#2 x = 16'd456; shift_amount = 5'd7; select = 1'b0;
		
	end
endmodule