//4 to 1 mux
module mux4_to_1(out, i0, i1, i2, i3, s0, s1);

output out;
input i0, i1, i2, i3;
input s0, s1;

wire s0n, s1n;
wire y0, y1, y2, y3;

not	(s0not, s0);
not	(s1not, s1);

and	(y0, i0, s0not, s1not);
and	(y1, i1, s0not, s1);
and	(y2, i2, s0, s1not);
and	(y3, i3, s0, s1);
or	(out, y0, y1, y2, y3);
endmodule

module logic_1b(out, a, b, select);
output out;
input a, b;
input [1:0] select;

wire  and_out, or_out, xor_out, nor_out;

and and_op(and_out, a, b);
or or_op(or_out, a, b);
xor xor_op(xor_out, a, b);
not nor_op(nor_out, or_out);
mux4_to_1 mux_op(out, and_out, or_out, xor_out, nor_out, select[1], select[0]);

endmodule

module logic_32b(out, a, b, select);
output [31:0] out;
input [31:0] a, b;
input [1:0] select;

logic_1b bit_0(out[0], a[0], b[0], select); 
logic_1b bit_1(out[1], a[1], b[1], select);
logic_1b bit_2(out[2], a[2], b[2], select);
logic_1b bit_3(out[3], a[3], b[3], select);
logic_1b bit_4(out[4], a[4], b[4], select);
logic_1b bit_5(out[5], a[5], b[5], select);
logic_1b bit_6(out[6], a[6], b[6], select);
logic_1b bit_7(out[7], a[7], b[7], select);
logic_1b bit_8(out[8], a[8], b[8], select);
logic_1b bit_9(out[9], a[9], b[9], select);
//
logic_1b bit_10(out[10], a[10], b[10], select);
logic_1b bit_11(out[11], a[11], b[11], select);
logic_1b bit_12(out[12], a[12], b[12], select);
logic_1b bit_13(out[13], a[13], b[13], select);
logic_1b bit_14(out[14], a[14], b[14], select);
logic_1b bit_15(out[15], a[15], b[15], select);
logic_1b bit_16(out[16], a[16], b[16], select);
logic_1b bit_17(out[17], a[17], b[17], select);
logic_1b bit_18(out[18], a[18], b[18], select);
logic_1b bit_19(out[19], a[19], b[19], select);
//
logic_1b bit_20(out[20], a[20], b[20], select);
logic_1b bit_21(out[21], a[21], b[21], select);
logic_1b bit_22(out[22], a[22], b[22], select);
logic_1b bit_23(out[23], a[23], b[23], select);
logic_1b bit_24(out[24], a[24], b[24], select);
logic_1b bit_25(out[25], a[25], b[25], select);
logic_1b bit_26(out[26], a[26], b[26], select);
logic_1b bit_27(out[27], a[27], b[27], select);
logic_1b bit_28(out[28], a[28], b[28], select);
logic_1b bit_29(out[29], a[29], b[29], select);
//
logic_1b bit_30(out[30], a[30], b[30], select);
logic_1b bit_31(out[31], a[31], b[31], select);

endmodule

module stimulus;
wire [31:0] z;
reg [31:0] x, y;
reg [1:0] select;
logic_32b logic_func(z, x, y, select);

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