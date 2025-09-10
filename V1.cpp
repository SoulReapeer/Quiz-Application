#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono> // for timer functions

using namespace std;

int main() {
    string playerName;
    char playOption;
    int score = 0;
    int timeLimit = 10; // Time limit per question in seconds

    // Questions and answers
    string questions[100] = {
        "What is the derivative of ex2e^{x^2} with respect to xx?",///01
        "In fluid mechanics, Bernoulli’s equation assumes:",///02
        "Which type of immunoglobulin is most abundant in human serum?",///03
        "What is the primary component of the Sun’s core?",///04
        "The process of transcription in eukaryotes occurs in:",///05
        "The hybridization of carbon in ethyne (acetylene, C2H2C_2H_2) is:",///06
        "The energy of a photon is given by:",///07
        "Which structure of a protein is determined by hydrogen bonding between backbone atoms?",///08
        "In a SWOT analysis, 'W' stands for:",///09
        "Which philosopher introduced the concept of 'categorical imperative'?",///10
        "Which of the following is NOT a type of logical fallacy?",///11
        "In fluid mechanics, Bernoulli’s equation assumes:",///12
        "Which type of immunoglobulin is most abundant in human serum?",///13
        "Which phase of the cardiac cycle involves ventricular contraction?",///14
        "What is the primary component of the Sun’s core?",///15
        "Which galaxy type is the most abundant in the universe?",///16
        "The process of transcription in eukaryotes occurs in:",///17
        "Which organelle is responsible for producing ATP?",///18
        "Which type of bond involves the sharing of electron pairs between atoms?",///19
        "Which law states that energy cannot be created or destroyed?",///20
        "Which structure of a protein is determined by hydrogen bonding between backbone atoms?",///21
        "The Michaelis-Menten constant () represents:",///22
        "What is the main product when ethanol is oxidized using acidified potassium dichromate?",///23
        "Which of the following is a key principle of financial accounting?",///24
        "The principle of STARE DECISIS  refers to:",///25
        "Which international organization oversees global intellectual property rights?",///26
        "Who wrote 'The Republic' a foundational work in Western philosophy?",///27
        "Which movement is associated with abstract expressionism in art?",///28
        "Which layer of Earth is primarily composed of iron and nickel?",///29
        "Which gas is a primary contributor to the greenhouse effect?",///30
        "Which class of animals is characterized by having hair and mammary glands?",///31
        "Coral reefs are primarily composed of:",///32
        "The event horizon of a black hole is defined as:",///33
        "Which spacecraft was the first to fly by Pluto?",///34
        "The effective temperature of the Sun's surface is approximately:",///35
        "Which term describes the distance light travels in one year?",///36
        "What is the integral of sin⁡(x)\sin(x) with respect to xx?",///37
        "Which of the following is a type of renewable energy?",///38
        "The Nyquist criterion is used to determine:",///39
        "In thermodynamics, which property is an extensive property?",///40
        "Which hormone regulates blood sugar levels by facilitating glucose uptake in cells?",///41
        "Which microorganism is responsible for tuberculosis?",///42
        "What is the name of the region around a star where liquid water could exist on a planet's surface?",///43
        "Which planet in the Solar System has the largest number of moons?",///44
        "In DNA, adenine pairs with:",///45
        "What is the main photosynthetic pigment in plants?",///46
        "What is the oxidation state of sulfur in H2SO4H_2SO_4?",///47
        "The bond angle in a water molecule is approximately:",///48
        "What is the SI unit of magnetic flux?",///49
        "Which type of wave is not capable of traveling through a vacuum?",///50
        "Enzymes are primarily composed of:",///51
        "Which of the following is an example of a competitive inhibitor?",///52
        "What does the term “liquidity” refer to in finance?",///53
        "Which leadership style involves delegating decision-making authority to subordinates?",///54
        "What does the term “habeas corpus” mean?",///55
        "Which law regulates anti-competitive practices in the European Union?",///56
        "What is the main purpose of a thesis in academic writing?",///57
        "In statistics, the mean of a data set is calculated by:",///58
        "In electrical circuits, the unit of inductance is:",///59
        "In computer networking, which protocol ensures reliable data transfer?",///60
        "The hormone responsible for regulating circadian rhythm is:",///61
        "Which vitamin is essential for blood clotting?",///62
        "Which planet has the highest surface temperature in the Solar System?",///63
        "The Hubble Space Telescope primarily observes in which type of light?",///64
        "What is the term for a sequence of DNA that codes for a specific protein?",///65
        "Which process results in the formation of gametes?",///66
        "Which element has the highest electronegativity?",///67
        "The pH of a neutral solution at 25°C is:",///68
        "The speed of light in a vacuum is approximately:",///69
        "The second law of thermodynamics states that:",///70
        "The most common secondary structure in proteins is",///71
        "ATP is primarily produced in which part of the cell?",///72
        "In economics, the law of demand states that:",///73
        "The primary goal of financial management is to:",///74
        "The concept of 'natural justice' includes principles of:",///75
        "Which legal system is primarily based on written statutes?",///76
        "Which philosopher is known for the concept of 'tabula rasa'?",///77
        "In academic research, a null hypothesis is:",///78
        "In thermodynamics, the Carnot cycle is:",///79
        "What is the primary function of a rectifier?",///80
        "The Glasgow Coma Scale is used to assess:",///81
        "Which of the following is an example of an autoimmune disease?",///82
        "The largest moon of Saturn is:",///83
        "The cosmic microwave background radiation is evidence for:",///84
        "Which process involves the exchange of genetic material between homologous chromosomes?",///85
        "The smallest unit of life capable of independent existence is:",///86
        "The bond angle in a water molecule is approximately:",///87
        "What is the standard molar volume of an ideal gas at STP (Standard Temperature and Pressure)?",///88
        "The Heisenberg Uncertainty Principle is mathematically expressed as:",///89
        "What is the SI unit of magnetic flux?",///90
        "Which molecule serves as the primary energy currency of the cell?",///91
        "Which technique is used to separate proteins based on size?",///92
        "A “bear market” in finance refers to:",///93
        "The four Ps of marketing include:",///94
        "In contract law, an offer is considered valid when:",///95
        "The International Court of Justice is located in:",///96
        "In genetic engineering, which enzyme is used to cut DNA at specific sequences?",///97
        "The Hardy-Weinberg principle assumes which of the following conditions?",///98
        "Which phenomenon demonstrates the wave nature of light?",///99
        "In special relativity, what remains constant for all observers?",///100
    };

    string options[100][4] = {

          /*1*/{"1) 2xex22xe^{x^2}","2) ex2e^{x^2}","3) x2ex2x^2e^{x^2}","4) xexx e^x"},///01
          /*2*/{"1) Compressible flow", "2) Viscous flow", "3) Steady and incompressible flow", "4) Ernest Hemingway"},
          /*3*/{"1) IgA", "b) IgE", "3) IgG", "4) IgM"},
          /*4*/{"1) Helium", "2) Hydrogen", "3) Carbon", "4) Iron"},
          /*5*/{"1) Ribosomes", "2) Cytoplasm", "3) Nucleus", "4) Golgi apparatus"},
          /*6*/{"1) sp3sp^3", "2) sp2sp^2", "3) spsp", "4) sp3dsp^3d"},
          /*7*/{"1) hvhv", "2) h/vh/v", "3) hc/λhc/\lambda", "4) Both a and c"},
          /*8*/{"1) Primary structure", "2) Secondary structure", "3) Tertiary structure", "4) Quaternary structure"},
          /*9*/{"1) Weakness", "2) Weight", "3) Worth", "4) Will"},
         /*10*/{"1) Kant", "2) Nietzsche", "3) Hume", "4) Locke"},
         /*11*/{"1) Ad Hominem", "2) Straw Man", "3) Red Herring", "4) Hindsight Bias"},
        /*12*/{ "1) Compressible flow","2) Viscous flow","3) Steady and incompressible flow","4) Variable density"},
        /*13*/{ "1) IgA","2) IgE","3) IgG","4) IgM"},
        /*14*/{ "1) Systole","2) Diastole","3) Isovolumetric Relaxation","4) Ventricular Filling"},
        /*15*/{ "1) Helium","2) Hydrogen","3) Carbon","4) Iron"},
        /*16*/{ "1) Spiral","2) Elliptical","3) Irregular","4) Lenticular"},
        /*17*/{ "1) Ribosomes","2) Cytoplasm","3) Nucleus","4) Golgi apparatus"},
        /*18*/{ "1) Nucleus","2) Mitochondria","3) Ribosomes","4) Endoplasmic Reticulum"},
        /*19*/{ "1) Ionic bond","2) Covalent bond","3) Metallic bond","4) Hydrogen bond"},
        /*20*/{ "1) First Law of Thermodynamics","2) Second Law of Thermodynamics","3) Conservation of Momentum","4) Coulomb's Law"},
        /*21*/{ "1) Primary structure","2) Secondary structure","3) Tertiary structure","4) Quaternary structure"},
        /*22*/{ "1) The maximum reaction rate","2) The substrate concentration at half the maximum reaction rate","3) The enzyme concentration","4) The rate of substrate binding"},
        /*23*/{ "1) Methane","2) Ethene","3) Acetaldehyde","4) Acetic acid"},
        /*24*/{ "1) Consistency","2) Diversity","3) Equity","4) Volatility"},
        /*25*/{ "1) Statutory interpretation","2) Precedent-based decision-making","3) Judicial activism","4) Case dismissal"},
        /*26*/{ "1) WTO","2) WIPO","3) IMF","4) UN"},
        /*27*/{ "1) Socrates","2) Plato","3) Aristotle","4) Descartes"},
        /*28*/{ "1) Surrealism","2) Impressionism","3) Cubism","4) Action painting"},
        /*29*/{ "1) Crust","2) Mantle","3) Outer core","4) Inner core"},
        /*30*/{ "1) Oxygen","2) Nitrogen","3) Carbon dioxide","4) Helium"},
        /*31*/{ "1) Reptiles","2) Amphibians","3) Mammals","4) Birds"},
        /*32*/{ "1) Silica","2) Calcium carbonate","3) Magnesium sulfate","4) Sodium chloride"},
        /*33*/{ "1) The distance at which light cannot escape","2) The boundary where gravity is zero","3) The surface of the singularity","4) The point of maximum radiation"},
        /*34*/{ "1) Voyager 1","2) New Horizons","3) Cassini","4) Hubble"},
        /*35*/{ "1) 4,000 K","2) 5,800K","3) 10,000 K","4) 15,000 K"},
        /*36*/{ "1) Astronomical Unit","2) Parsec","3) Light-Year","4) Kilometer"},
        /*37*/{ "1) cos⁡(x)\cos(x)","2) −cos⁡(x)-\cos(x)","3) −sin⁡(x)-\sin(x)","4) tan⁡(x)\tan(x)"},
        /*38*/{ "1) Natural Gas","2) Solar Energy","3) Nuclear Energy","4) Coal"},
        /*39*/{ "1) Stability of a control system","2) Power efficiency","3) Signal distortion","4) Material strength"},
        /*40*/{ "1) Pressure","2) Temperature","3) Entropy","4) Density"},
        /*41*/{ "1) Glucagon","2) Insulin","3) Adrenaline","4) Cortisol"},
        /*42*/{ "1) Escherichia coli","2) Mycobacterium tuberculosis","3) Streptococcus pneumoniae","4) Bacillus anthracis"},
        /*43*/{ "1) Kuiper Belt","2) Goldilocks Zone","3) Oort Cloud","4) Schwarzschild Radius"},
        /*44*/{ "1) Jupiter","2) Saturn","3) Uranus","4) Neptune"},
        /*45*/{ "1) Cytosine","2) Thymine","3) Guanine","4) Uracil"},
        /*46*/{ "1) Chlorophyll a","2) Carotene","3) Xanthophyll","4) Anthocyanin"},
        /*47*/{ "1) +4","2) +6","3) -2","4) 0"},
        /*48*/{ "1) 90°","2) 104.5°","3) 109.5°","4) 120°"},
        /*49*/{ "1) Tesla","2) Weber","3) Henry","4) Gauss"},
        /*50*/{ "1) Radio waves","2) Sound waves","3) Light waves","4) X-rays"},
        /*51*/{ "1) Nucleotides","2) Lipids","3) Proteins","4) Carbohydrates"},
        /*52*/{ "1) ATP in glycolysis","2) Malonate in succinate dehydrogenase","3) FAD in electron transport chain","4) NAD+ in Krebs cycle"},
        /*53*/{ "1) Profitability of assets","2) Conversion of assets to cash","3) Return on investments","4) Reduction in liabilities"},
        /*54*/{ "1) Autocratic","2) Democratic","3) Laissez-faire","4) Transformational"},
        /*55*/{ "1) By the court’s authority","2) Produce the body","3) Let the buyer beware","4) The thing speaks for itself"},
        /*56*/{ "1) Sherman Act","2) Competition Act","3) GDPR","4) Article 101 of TFEU"},
        /*57*/{ "1) To summarize existing knowledge","2) To propose a central argument or idea","3) To provide examples of a topic","4) To list references"},
        /*58*/{ "1) Dividing the sum of all values by the number of values","2) Finding the middle value of the sorted data set","3) Calculating the square root of the variance","4) Determining the most frequent value"},
        /*59*/{ "1) Tesla","2) Farad","3) Henry","4) Coulomb"},
        /*60*/{ "1) TCP","2) UDP","3) HTTP","4) FTP"},
        /*61*/{ "1) Insulin","2) Melatonin","3) Thyroxine","4) Adrenaline"},
        /*62*/{ "1) Vitamin A","2) Vitamin B12","3) Vitamin C","4) Vitamin K"},
        /*63*/{ "1) Mercury","2) Venus","3) Mars","4) Jupiter"},
        /*64*/{ "1) Radio waves","2) Visible and ultraviolet","3) Gamma rays","4) Infrared"},
        /*65*/{ "1) Genome","2) Gene","3) Chromosome","4) Codon"},
        /*66*/{ "1) Mitosis","2) Meiosis","3) Binary fission","4) Budding"},
        /*67*/{ "1) Oxygen","2) Fluorine","3) Nitrogen","4) Chlorine"},
        /*68*/{ "1) 0","2) 7","3) 14","4) 1"},
        /*69*/{ "1) 3×1083 \times 10^8 m/s","2) 3×1063 \times 10^6 m/s","3) 3×10103 \times 10^10 m/s","4) 3×10123 \times 10^12 m/s"},
        /*70*/{ "1) Energy cannot be created or destroyed","2) The entropy of an isolated system always increases","3) For every action, there is an equal and opposite reaction","4) Energy transfer is 100% efficient"},
        /*71*/{ "1) Alpha helix","2) Beta sheet","3) Random coil","4) Both a and b"},
        /*72*/{ "1) Cytoplasm","2) Mitochondria","3) Golgi apparatus","4) Ribosome"},
        /*73*/{ "1) Higher prices lead to higher demand","2) Lower prices lead to higher demand","3) Price has no effect on demand","4) Demand is inversely proportional to supply"},
        /*74*/{ "1) Maximize revenue","2) Maximize shareholder wealth","3) Minimize costs","4) Ensure customer satisfaction"},
        /*75*/{ "1) Equity and common sense","2) Bias and discrimination","3) Autocracy and sovereignty","4) Speedy and non-transparent trials"},
        /*76*/{ "1) Common law","2) Civil law","3) Islamic law","4) Tribal law"},
        /*77*/{ "1) John Locke","2) Immanuel Kant","3) Friedrich Nietzsche","4) René Descartes"},
        /*78*/{ "1) The hypothesis being tested for rejection","2) A hypothesis that is always accepted","3) A statement of causation","4) An untestable claim"},
        /*79*/{ "1) An idealized thermodynamic cycle","2) A practical refrigeration cycle","3) An isothermal expansion process","4) A heat transfer process in engines"},
        /*80*/{ "1) Amplify signals","2) Convert AC to DC","3) Store electrical energy","4) Measure current"},
        /*81*/{ "1) Heart function","2) Liver damage","3) Neurological function","4) Lung capacity"},
        /*82*/{ "1) Diabetes mellitus type 2","2) Rheumatoid arthritis","3) Tuberculosis","4) Influenza"},
        /*83*/{ "1) Europa","2) Titan","3) Ganymede","4) Callisto"},
        /*84*/{ "1) Dark energy","2) The Big Bang theory","3) Galaxy formation","4) Black hole evaporation"},
        /*85*/{ "1) Crossing over","2) Independent assortment","3) Fertilization","4) DNA replication"},
        /*86*/{ "1) Atom","2) Cell","3) Tissue","4) Organelle"},
        /*87*/{ "1) 180∘180^\circ","2) 109.5∘109.5^\circ","3) 120∘120^\circ","4) 104.5∘104.5^\circ"},
        /*88*/{ "1) 22.4 L","2) 24.0 L","3) 20.1 L","4) 18.0 L"},
        /*89*/{ "1) ΔxΔp≥h4π\Delta x \Delta p \geq \frac{h}{4\pi}","2) E=mc2E = mc^2","3) F=maF = ma","4) ΔEΔt≤h\Delta E \Delta t \leq h"},
        /*90*/{ "1) Tesla","2) Weber","3) Gauss","4) Ampere"},
        /*91*/{ "1) DNA","2) ATP","3) NADH","4) Glucose"},
        /*92*/{ "1) Western blotting","2) Gel filtration chromatography","3) SDS-PAGE","4) Mass spectrometry"},
        /*93*/{ "1) A market with rising stock prices","2) A market with falling stock prices","3) A stable stock market","4) A volatile stock market"},
        /*94*/{ "1) Product, Price, Process, Performance","2) Product, Price, Place, Promotion","3) Planning, People, Price, Place","4) Price, Promotion, Profit, People"},
        /*95*/{ "1) It is vague and open to interpretation","2) It is clear, definite, and communicated","3) It is implied but not communicated","4) It is agreed upon without acceptance"},
        /*96*/{ "1) Geneva","2) New York","3) The Hague","4) Paris"},
        /*97*/{ "1) DNA polymerase","2) Ligase","3) Restriction endonuclease","4) Helicase"},
        /*99*/{ "1) Non-random mating","2) Natural selection","3) Large population size","4) Mutation occurring frequently"},
        /*99*/{ "1) Photoelectric effect","2) Double-slit experiment","3) Compton scattering","4) Zeeman effect"},
        /*100*/{ "1) Velocity of light","2) Time intervals","3) Length of objects","4) Mass of moving particles"},
    };
                             //1,2,3,4,5,6,7,8,9,0,
    int correctAnswers[100] = {1,3,3,2,3,3,4,2,1,1,//0
                               4,3,3,1,2,2,3,2,2,1,//1
                               2,2,3,1,2,2,2,4,4,3,//2
                               3,2,1,2,2,3,2,2,1,3,//3
                               2,2,2,2,2,1,2,2,2,2,//4
                               3,2,2,3,2,4,2,1,3,1,//5
                               2,4,2,2,2,2,2,2,1,2,//6
                               4,2,2,2,1,2,1,1,1,2,//7
                               3,2,2,2,1,2,4,1,1,2,//8
                               2,3,2,2,2,3,3,3,2,1,//9
                               };

    srand(time(0));

    vector<int> selectedIndices;
    while (selectedIndices.size() < 10) {
        int randIndex = rand() % 100;
        if (find(selectedIndices.begin(), selectedIndices.end(), randIndex) == selectedIndices.end()) {
            selectedIndices.push_back(randIndex);
        }
    }

    cout << "Enter your name: ";
    getline(cin, playerName);

    cout << "Hello, " << playerName << "! Do you want to play the quiz game? (y/n): ";
    cin >> playOption;

    if (playOption == 'y' || playOption == 'Y') {
        auto totalStart = chrono::steady_clock::now(); // Start the total timer

        for (int i = 0; i < 10; i++) {
            int questionIndex = selectedIndices[i];
            cout << "Question " << i + 1 << ": " << questions[questionIndex] << endl;
            for (int j = 0; j < 4; j++) {
                cout << options[questionIndex][j] << endl;
            }
            cout << "You have " << timeLimit << " seconds to answer!" << endl;

            // Start timer for individual question
            auto start = chrono::steady_clock::now();
            int userAnswer;

            cin >> userAnswer;

            // Calculate elapsed time for the question
            auto end = chrono::steady_clock::now();
            auto elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();

            if (elapsed > timeLimit) {
                cout << "Time's up! The correct answer was " << correctAnswers[questionIndex] << "." << endl;
            } else if (userAnswer == correctAnswers[questionIndex]) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Incorrect. The correct answer was " << correctAnswers[questionIndex] << "." << endl;
            }
            cout << "Time taken for this question: " << elapsed << " seconds\n" << endl;
        }

        auto totalEnd = chrono::steady_clock::now(); // End the total timer
        auto totalTime = chrono::duration_cast<chrono::seconds>(totalEnd - totalStart).count(); // Calculate total time

        cout << "Quiz over! " << playerName << ", you scored " << score << " out of 10." << endl;
        cout << "Total time taken for the quiz: " << totalTime << " seconds" << endl;

        if (score == 0) {
            cout << "Grade: Need studying." << endl;
        } else if (score >= 1 && score <= 4) {
            cout << "Grade: Try better next time." << endl;
        } else if (score == 5) {
            cout << "Grade: Not Good but Not Bad." << endl;
        } else if (score >= 6 && score <= 7) {
            cout << "Grade: Good but Try harder." << endl;
        } else if (score >= 8 && score <= 9) {
            cout << "Grade: Very good and Keep it up!" << endl;
        } else if (score == 10) {
            cout << "Grade: Excellent!!!" << endl;
        }
    }
     else {
        cout << "Game ended. Thank you, " << playerName << "!" << endl;
    }

    return 0;
}
