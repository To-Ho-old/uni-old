//2-1 mux
module mux2_to_1(out, d0, d1, s0);
output out;
input d0, d1, s0;

wire y0, y1, s0n;

and(y1, d1, s0);
not(s0n, s0);
and(y0, s0n, d0);
or(out, y0, y1);

endmodule

//5 bit 2-1 mux
module mux2_to_1_5bit(out, d0, d1, s0);
output [4:0] out;
input [4:0] d0, d1;
input s0;

mux2_to_1 bit0(out[0], d0[0], d1[0], s0);
mux2_to_1 bit1(out[1], d0[1], d1[1], s0);
mux2_to_1 bit2(out[2], d0[2], d1[2], s0);
mux2_to_1 bit3(out[3], d0[3], d1[3], s0);
mux2_to_1 bit4(out[4], d0[4], d1[4], s0);

endmodule

module stimulus;
reg [4:0] d0, d1;
reg S;
wire [4:0] OUT;

mux2_to_1_5bit mymux1(OUT, d0, d1, S);

initial
	begin 
	d0[4:0] = 5'd10;
	d1[4:0] = 5'd20;
	#1 $display("d0 = %b\n", d0);
	#1 $display("d1 = %b\n", d1);

	
	//0
	S = 1'b0;
	#5 $display("S = %b, OUT1 = %b\n", S, OUT);
	
	//1
	S = 1'b1;
	#5 $display("S = %b, OUT2 = %b\n", S, OUT);
	end
endmodule