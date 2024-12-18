#include <GuiFoundation/GuiFoundationPCH.h>

#include <Foundation/Math/Math.h>
#include <GuiFoundation/Widgets/ImageWidget.moc.h>
#include <QGraphicsPixmapItem>
#include <QScrollArea>
#include <QScrollBar>

nsQtImageScene::nsQtImageScene(QObject* pParent)
  : QGraphicsScene(pParent)
{
  m_pImageItem = nullptr;
  setItemIndexMethod(QGraphicsScene::NoIndex);
}

void nsQtImageScene::SetImage(QPixmap pixmap)
{
  if (m_pImageItem)
    delete m_pImageItem;

  m_Pixmap = pixmap;
  m_pImageItem = addPixmap(m_Pixmap);
  setSceneRect(0, 0, m_Pixmap.width(), m_Pixmap.height());
}



nsQtImageWidget::nsQtImageWidget(QWidget* pParent, bool bShowButtons)
  : QWidget(pParent)
{
  setupUi(this);
  m_pScene = new nsQtImageScene(GraphicsView);
  GraphicsView->setScene(m_pScene);

  m_fCurrentScale = 1.0f;

  if (!bShowButtons)
    ButtonBar->setVisible(false);
}

nsQtImageWidget::~nsQtImageWidget() = default;

void nsQtImageWidget::SetImageSize(float fScale)
{
  if (m_fCurrentScale == fScale)
    return;

  m_fCurrentScale = fScale;
  ImageApplyScale();
}

void nsQtImageWidget::ScaleImage(float fFactor)
{
  float fPrevScale = m_fCurrentScale;
  m_fCurrentScale = nsMath::Clamp(m_fCurrentScale * fFactor, 0.2f, 5.0f);

  ImageApplyScale();
}

void nsQtImageWidget::ImageApplyScale()
{
  QTransform scale = QTransform::fromScale(m_fCurrentScale, m_fCurrentScale);
  GraphicsView->setTransform(scale);
}

void nsQtImageWidget::SetImage(QPixmap pixmap)
{
  m_pScene->SetImage(pixmap);
  ImageApplyScale();
}

void nsQtImageWidget::on_ButtonZoomIn_clicked()
{
  ScaleImage(1.25f);
}

void nsQtImageWidget::on_ButtonZoomOut_clicked()
{
  ScaleImage(0.75f);
}

void nsQtImageWidget::on_ButtonResetZoom_clicked()
{
  SetImageSize(1.0f);
}