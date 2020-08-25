
#the text is hidden at position with spaces as composite numbers

txt="tKybphbQzpWiegaUcrVGMfhwcCWlWFPlELBCBCnsvyasxOFiXcIWxTOgZHfcxpDeawTocXiOtissrSNFOSpqCusrmtJvZeGkmCnfbAGmzvWxGnfQXGOYWdkNVPanbNmyTEsvSnxGhImImqfljTtNYddfBHTKAeFXgXlVxiXnFPsrfpGsQmliBLBnmgqpcxEJvJcMAvuxySsGoBHxkFDjvifEJUCelgQUYUUpYQjpoBCmnESoJxxXCAoyzMvKKBjNXlFxwliWKwupnhdznlkcqHAEvyifPMlJQuzzMwsBPQCjLyHokCeEslUeTGAQpQuwFtApSZxmPqPvWepntMMiJnRiwpEjBvmkTzrOrLOKjBtNsemPkPTSufmtMDRzffdKaiRiKZbgsrNGUTPGubGSFghIfImtVMEPmFslSmXknTdzqsPGYszZgacJGFTLubcWolQiuDCpeLiaFbPwFpvtPvDMCAMODrcgtfhdofSDTQoysPnCMvDlLIMOWtgIMiBNUdKmbwIObQiXvCGoo"

ans=""
i=0
#list of all composites
len1=[4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30, 32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 46, 48, 49, 50, 51, 52, 54, 55, 56, 57, 58, 60, 62, 63, 64, 65, 66, 68, 69, 70, 72, 74, 75, 76, 77, 78, 80, 81, 82, 84, 85, 86, 87, 88, 90, 91, 92, 93, 94, 95, 96, 98, 99, 100, 102, 104, 105, 106, 108, 110, 111, 112, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 128, 129, 130, 132, 133, 134, 135, 136, 138, 140, 141, 142, 143, 144, 145, 146, 147, 148, 150,  152, 154, 155, 156, 157, 158, 159, 160, 162, 164, 165, 166, 168, 170, 172, 174, 175, 176, 177, 178, 180, 182, 184, 185, 186, 187, 188, 189, 190, 192, 194, 195, 196, 198]


while i<529:
    ans+=txt[i]
  
    i+=len1[0]+1
    len1.pop(0)
print(ans)