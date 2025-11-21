
module mux2to1(
    input A1, A0, S,
    output X
);

    wire sbar, and1, and2;

    not (sbar, s);

    and (and1, sbar, A0);
    and (and2, s, A1);

    or(X. and1, and2);
endmodule


module Mux4to1(
    input A3, A2, A1, A0, S1, S0,
    output X
);

    wire X1, X0;

    mux2to1 mux1 (A3, A2, S0, X1);
    mux2to1 mux0 (A1, A0, S0, X0);
    mux2to1 muxout(X1, X0, S1, X);

endmodule
