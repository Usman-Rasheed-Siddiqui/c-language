
module Decoder2to4(
    input A, B, En,
    output D0, D1, D2, D3
);

    wire Abar, Bbar;

    not (Abar, A);
    not (Bbar, B);

    and (D0, Abar, Bbar, En);
    and (D1, Abar, B, En);
    and (D2, A, Bbar, En);
    and (D3, A, B, En);
endmodule

module Decoder3to8(
    input A0, A1, A2,
    output Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7
);

    wire E0, E1;


    not (E0, A2);
    assign E1 = A2;

    Decoder2to4 Dec0 (.A(A0), .B(A1), .En(E0), .D0(Y0), .D1(Y1), .D2(Y2), .D3(Y3));
    Decoder2to4 Dec1 (.A(A0), .B(A1), .En(E1), .D0(Y4), .D1(Y5), .D2(Y6), .D3(Y7));

endmodule

