//Tony Ho
//CPSC 4210
//Project: ALU with gate-level modelling

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

//8-bit 4-1 mux
module mux4_to_1_8b(out, d0, d1, d2, d3, s);
output [7:0] out;
input [7:0] d0;
input [7:0] d1;
input [7:0] d2;
input [7:0] d3;
input [1:0] s;

mux4_to_1 mux0(out[0], d0[0], d1[0], d2[0], d3[0], s[1], s[0]);
mux4_to_1 mux1(out[1], d0[1], d1[1], d2[1], d3[1], s[1], s[0]);
mux4_to_1 mux2(out[2], d0[2], d1[2], d2[2], d3[2], s[1], s[0]);
mux4_to_1 mux3(out[3], d0[3], d1[3], d2[3], d3[3], s[1], s[0]);
mux4_to_1 mux4(out[4], d0[4], d1[4], d2[4], d3[4], s[1], s[0]);
mux4_to_1 mux5(out[5], d0[5], d1[5], d2[5], d3[5], s[1], s[0]);
mux4_to_1 mux6(out[6], d0[6], d1[6], d2[6], d3[6], s[1], s[0]);
mux4_to_1 mux7(out[7], d0[7], d1[7], d2[7], d3[7], s[1], s[0]);

endmodule

//32-bit 4-1 mux
module mux4_to_1_32b(out, d0, d1, d2, d3, s);
output [31:0] out;
input [31:0] d0;
input [31:0] d1;
input [31:0] d2;
input [31:0] d3;
input [1:0] s;

mux4_to_1_8b mux0(out[7:0], d0[7:0], d1[7:0], d2[7:0], d3[7:0], s);
mux4_to_1_8b mux1(out[15:8], d0[15:8], d1[15:8], d2[15:8], d3[15:8], s);
mux4_to_1_8b mux2(out[23:16], d0[23:16], d1[23:16], d2[23:16], d3[23:16], s);
mux4_to_1_8b mux3(out[31:24], d0[31:24], d1[31:24], d2[31:24], d3[31:24], s);

endmodule

//32 bit shifter
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

//32-bit Add-sub
//Full adder
module full_adder(c_out, sum, a, b, c_in);

output sum, c_out;
input a, b;
input c_in;

wire ab, axob, abc;

xor(axob, a, b);
and(ab, a, b);

xor(sum, axob, c_in);
and(abc, axob, c_in);
or(c_out, ab, abc);

endmodule

//add-sub function, includes xor
module add_sub(cc, ss, a, b, c);

output [31:0] ss;
output cc;
input [31:0] a, b;
input c;

wire [30:0] carry;
wire [31:0] y;

xor (y[0], b[0], c);
xor (y[1], b[1], c);
xor (y[2], b[2], c);
xor (y[3], b[3], c);
xor (y[4], b[4], c);
xor (y[5], b[5], c);
xor (y[6], b[6], c);
xor (y[7], b[7], c);
xor (y[8], b[8], c);
xor (y[9], b[9], c);
xor (y[10], b[10], c);
xor (y[11], b[11], c);
xor (y[12], b[12], c);
xor (y[13], b[13], c);
xor (y[14], b[14], c);
xor (y[15], b[15], c);
xor (y[16], b[16], c);
xor (y[17], b[17], c);
xor (y[18], b[18], c);
xor (y[19], b[19], c);
xor (y[20], b[20], c);
xor (y[21], b[21], c);
xor (y[22], b[22], c);
xor (y[23], b[23], c);
xor (y[24], b[24], c);
xor (y[25], b[25], c);
xor (y[26], b[26], c);
xor (y[27], b[27], c);
xor (y[28], b[28], c);
xor (y[29], b[29], c);
xor (y[30], b[30], c);
xor (y[31], b[31], c);

full_adder fa0(carry[0], ss[0], a[0], y[0], c);
full_adder fa1(carry[1], ss[1], a[1], y[1], carry[0]);
full_adder fa2(carry[2], ss[2], a[2], y[2], carry[1]);
full_adder fa3(carry[3], ss[3], a[3], y[3], carry[2]);
full_adder fa4(carry[4], ss[4], a[4], y[4], carry[3]);
full_adder fa5(carry[5], ss[5], a[5], y[5], carry[4]);
full_adder fa6(carry[6], ss[6], a[6], y[6], carry[5]);
full_adder fa7(carry[7], ss[7], a[7], y[7], carry[6]);
full_adder fa8(carry[8], ss[8], a[8], y[8], carry[7]);
full_adder fa9(carry[9], ss[9], a[9], y[9], carry[8]);
full_adder fa10(carry[10], ss[10], a[10], y[10], carry[9]);
full_adder fa11(carry[11], ss[11], a[11], y[11], carry[10]);
full_adder fa12(carry[12], ss[12], a[12], y[12], carry[11]);
full_adder fa13(carry[13], ss[13], a[13], y[13], carry[12]);
full_adder fa14(carry[14], ss[14], a[14], y[14], carry[13]);
full_adder fa15(carry[15], ss[15], a[15], y[15], carry[14]);
full_adder fa16(carry[16], ss[16], a[16], y[16], carry[15]);
full_adder fa17(carry[17], ss[17], a[17], y[17], carry[16]);
full_adder fa18(carry[18], ss[18], a[18], y[18], carry[17]);
full_adder fa19(carry[19], ss[19], a[19], y[19], carry[18]);
full_adder fa20(carry[20], ss[20], a[20], y[20], carry[19]);
full_adder fa21(carry[21], ss[21], a[21], y[21], carry[20]);
full_adder fa22(carry[22], ss[22], a[22], y[22], carry[21]);
full_adder fa23(carry[23], ss[23], a[23], y[23], carry[22]);
full_adder fa24(carry[24], ss[24], a[24], y[24], carry[23]);
full_adder fa25(carry[25], ss[25], a[25], y[25], carry[24]);
full_adder fa26(carry[26], ss[26], a[26], y[26], carry[25]);
full_adder fa27(carry[27], ss[27], a[27], y[27], carry[26]);
full_adder fa28(carry[28], ss[28], a[28], y[28], carry[27]);
full_adder fa29(carry[29], ss[29], a[29], y[29], carry[28]);
full_adder fa30(carry[30], ss[30], a[30], y[30], carry[29]);
full_adder fa31(cc, ss[31], a[31], y[31], carry[30]);

endmodule

//1-bit logic unit
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

//32-bit logic unit
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

//alu
module ALU_32bits (s, a, b, c_0, Const_Var, shift_direction, Function_class, Logic_function, Const_amount);
output [31:0] s;
input [31:0] a, b;
input c_0;		//c_0 = Add' Sub
input Const_Var, shift_direction;
input [1:0] Function_class;
input [1:0] Logic_function;
input [4:0] Const_amount;

wire [31:0] add_sub_ab_msb;
wire [4:0] Amount;
wire [31:0] shifted_b, logic_ab, add_sub_ab;

//Shifter
mux2_to_1_5bit mymux2_to_1_5b (Amount, Const_amount, a[4:0], Const_Var);
shifter myShifter (shifted_b, b, Amount, shift_direction);

//Add-sub
add_sub myadd_sub ( , add_sub_ab, a, b, c_0);

//Logic
logic_32b mylogic (logic_ab, a, b, Logic_function);

//32-bit 4-1 mux
assign add_sub_ab_msb[0] = add_sub_ab[31];
assign add_sub_ab_msb[31:1] = 0;
mux4_to_1_32b functionChoose (s, shifted_b, add_sub_ab_msb, add_sub_ab, logic_ab, Function_class);

endmodule

//--------stimulus module
// The ALU module name and orders of inputs, outputs should be same as the ALU module in the following
// H. Li

module stimulus;

//inputs
reg[31:0] A,B;
reg C_0,Const_Var,shift_direction;
reg [1:0] Function_class;
reg [1:0] Logic_function;
reg [4:0] Const_amount; 


//outputs
wire[31:0] s;



ALU_32bits my_ALU (s,  A, B,  C_0, Const_Var, shift_direction, Function_class, Logic_function, Const_amount);

 

initial  
begin 

$monitor($time,"A=%d|%b, B=%d|%b, C_IN=%b,-- Function_class=%d, shift_direction=%b, Const_Var=%b, Const_amount=%d, shift_direction=%b, Logic_function=%d,--OUTPUT=%d|%b \n",A,A,B,B,C_0,Function_class,shift_direction,Const_Var,Const_amount,shift_direction,Logic_function,s,s);
end

initial
begin
A=4'd0; B=4'd0; C_0=1'b0;
#5 A=8'd19; B=8'd55; Function_class[1]=1; Function_class[0]=0;  
#5 A=8'd59; B=8'd38;C_0=1'b1; Function_class[1]=0; Function_class[0]=1;  
#5 A=8'd39; B=8'd136; C_0=1'b1;  Function_class[1]=1; Function_class[0]=0; 
#5 A=16'd9; B=4'd112; Function_class[1]=0; Function_class[0]=0; shift_direction=1; Const_Var=1; 

#5 A=16'd129; B=16'd456;Function_class[1]=0; Function_class[0]=0;shift_direction=0;Const_Var=0;Const_amount=5'd7;  
#5 A=16'd656; B=8'd218; C_0=1'b0;Function_class[1]=1; Function_class[0]=1;Logic_function=2'd0;  
#5 A=8'd195; B=8'd228; C_0=1'b1;Function_class[1]=1; Function_class[0]=1;Logic_function=2'd1; 
#5 A=8'd99; B=16'd286; C_0=1'b1;Function_class[1]=1; Function_class[0]=1;Logic_function=2'd2; 
#5 A=8'd77; B=16'd486; C_0=1'b0;Function_class[1]=1; Function_class[0]=1;Logic_function=2'd3; 
end

endmodule