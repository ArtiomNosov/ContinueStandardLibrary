#pragma once
/*
*	UILR32Y1SCycle.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
enum class UILR32Y1SMenuCodes;
void UIUILR32Y1SCycle();
enum class UILR32Y1SGraphMenuCodes;
void GraphMenu();
enum class UILR32Y1SGraphIdTypeMenuCodes;
void ÑhoiceGraphIdTypeMenu(UILR32Y1SGraphMenuCodes graphTy);
enum class UILR32Y1SWorkWithGraphMenuCodes;
template<class GraphTy>
void outputGraph(GraphTy& g);
template<class VertexTy, class IdTy, class GraphTy>
void inputGraph(GraphTy& g);
template<class GraphTy, class VertexTy, class IdTy>
void WorkWithGraphMenu();
